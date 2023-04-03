// read file from disk
import fs from "node:fs";

const renderJSON = async (path: string) => {
  const file = fs.readFileSync(path, "utf-8");

  let count = 0;
  const now = Date.now();
  while (Date.now() - now < 1000) {
    JSON.parse(file);
    count++;
  }
  const last = Date.now() - now;

  // size to humanize
  const size = file.length * count;
  const i = Math.floor(Math.log(size) / Math.log(1024));
  const humanSize =
    (size / Math.pow(1024, i)).toFixed(2) +
    " " +
    ["B", "kB", "MB", "GB", "TB", "PB"][i];

  // Log
  console.table({
    path,
    count,
    size,
    humanSize,
    time: last + "ms",
  });
  // console.log(`Parsed ${count} times in 1 second`);
  // // size
  // console.log(
  //   `Size: ${file.length} bytes, total rendered bytes ${
  //     file.length * count
  //   } and ${humanSize}`
  // );
};

const main = async () => {
  // read folder in file list
  const files = fs.readdirSync("./bulker");

  // loop through files
  for (const file of files) {
    if (!file.endsWith(".json")) continue;
    // render json
    try {
      await renderJSON("./bulker/" + file);
    } catch (error) {
      console.log(file, error);
    }
  }
};

await main();
