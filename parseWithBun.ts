// read file from disk
import fs from "node:fs";
import process from "node:process";
import * as Bun from "bun"

Bun.gc(false);

type ResponseBench = {
  path: string;
  count: number;
  fileSize: number | string;
  processingSize: string;
  time: string;
  memory: string;
  cpu: string;
}

const toHumanUsage = (bytes: number) => {
  const i = Math.floor(Math.log(bytes) / Math.log(1024));
  return (
    (bytes / Math.pow(1024, i)).toFixed(2) +
    " " +
    ["B", "kB", "MB", "GB", "TB", "PB"][i]
  );
};
const renderJSON = async (path: string) => {
  try {
    let response = {} as ResponseBench;
    let count = 0;
    const now = Date.now();
    const beforeMemUsage = process.memoryUsage.rss();
    const beforeCpuUsage = process.cpuUsage().user;
    const file = Bun.file(path, { type: "application/json" });

    while (Date.now() - now < 1000) {
      // JSON.parse(fileContent);
      await file.json()

      count++;
    }
    const afterMemUsage = process.memoryUsage.rss();
    const afterCpuUsage = process.cpuUsage().user;
    const last = Date.now() - now;

    // size to humanize
    const fileSize = file.size
    const size = fileSize * count;
    const humanSize = toHumanUsage(size);
    response = {
      path,
      count,
      fileSize: toHumanUsage(fileSize),
      processingSize: humanSize,
      time: (count / last).toFixed(2) + " op/ms",
      memory: toHumanUsage(afterMemUsage - beforeMemUsage),
      cpu: `${((100 * last) / (afterCpuUsage - beforeCpuUsage)).toFixed(3)}%`,
    };

    return response;
  } catch (error) {
    console.error(path, error);
  }


};

const main = async () => {
  // read folder in file list
  const files = fs.readdirSync("./bulker");
  const responseList: ResponseBench[] = [];
  // loop through files
  for await (const file of files) {
    if (!file.endsWith(".json")) continue;
    // render json
    try {
      const response = await renderJSON("./bulker/" + file);
      if (!response) continue;
      responseList.push(response);
    } catch (error) {
      console.error(file, error);
    }
  }
  console.table(responseList);
  // console.table(arrayToTSV(responseList));

};


await main();
