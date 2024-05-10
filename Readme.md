# Bon File Format

## Global Scoping
Bon file format is a binary file format. It is a data serialization format used primarily for data storage and transfer of data over network connections. It is an alternative to XML, JSON, CSV, and other data formats. It is a binary format in which data is stored in a sequence of bytes of varying length. It is designed to be compact and fast for both small and large data. It is a self-describing format in that it contains information about the data it stores in the file itself. It is also a language-independent format, meaning it can be used across programming languages.

Also the bon data format has been adjusted to work on streaming. This means that bon will read the datasheets as needed instead of keeping them completely in memory. Also bon can maintain the data structure in more than one format. In particular, it allows extremely large data sets to work in full compliance with the specified algorithm

In short, data size is not a factor to worry about when using bon.  It will also increase p2p data security with its page state feature that allows you to manage decentralized data distribution in web streams on the client.

## Structure
### Global Start/end scope (0x00)

### Page Header 
<!-- Encoding: 0x01 0x(UTF-8 hex value)
Bon Version: 0x02 0x(Version hex value)
Revision: 0x03 0x(Revision hex value)
Total Body Row Count: 0x04 0x(Count hex value)
Total Body Size: 0x05 0x(Size hex value)
Compression Algorithm: 0x06 0x(Algorithm hex value) (is Compressed 0x01, is not compressed 0x00) -->
| Feature               | Hex Value | Description           | Example                                                                     |
| --------------------- | --------- | --------------------- | --------------------------------------------------------------------------- |
| Encoding              | `0x01 +`  | UTF-8                 | `0x01 0x(UTF-8 hex value)`                                                  |
| Bon Version           | `0x02 +`  | Bon Version           | `0x02 0x(Version hex value)`                                                |
| Revision              | `0x03 +`  | Bon Revision          | `0x03 0x(Revision hex value)`                                               |
| Total Body Row Count  | `0x04 +`  | Total Body Row Count  | `0x04 0x(Count hex value)`                                                  |
| Total Body Size       | `0x05 +`  | Total Body Size       | `0x05 0x(Size hex value)`                                                   |
| Compression Algorithm | `0x06 +`  | Compression Algorithm | `0x06 0x(Algorithm hex value) (is Compressed 0x01, is not compressed 0x00)` |


### Feature Scoping
| Feature               | Hex Value | Description           | Example |
| --------------------- | --------- | --------------------- | ------- |
| End of block/page/row | `0x00`    | End of block/page/row | `0x00`  |
| Precision             | `0x00`    | precision             | `0x00`  |
| Counter Reset         | `0x02`    | Counter Reset         | `0x02`  |


### Columns Types

#### Numerics
Numeric data types are numbers stored in database columns. These data types are typically grouped by: Exact numeric types, which store values exactly as specified. The exact numeric types are INTEGER, BIGINT, DECIMAL, NUMERIC, SMALLINT, and TINYINT. Approximate numeric types, which store floating-point values. The approximate numeric types are FLOAT, REAL, and DOUBLE PRECISION.
| Type          | Hex Value       | Description | Example                         |
| ------------- | --------------- | ----------- | ------------------------------- |
| Number(Smart) | `01  +`         | Integer     | `01  {value}`                   |
| Integer       | `01 00 {value}` | Number      | `01 00 07 B5`                   |
| Float         | `01 01 {value}` | Number      | `01 01 40 48 F5 C3 50 00 00 00` |
| Double        | `01 02 {value}` | Number      | `01 02 40 09 21 FB 54 44 2D 18` |
| Long          | `01 03 {value}` | Number      | `01 03 40 09 21 FB 54 44 2D 18` |
| Hex           | `01 04 {value}` | Number      | `01 04 40 09 21 FB 54 44 2D 18` |


#### Strings
Strings are sequences of characters. Strings are surrounded by double quotes. The characters within a string may be any Unicode characters except for the double quote with the hexadecimal value 0x22, the backslash with the hexadecimal value 0x5C, and the control characters with hexadecimal values 0x00 through 0x1F.

| Type          | Hex Value       | Description | Example                         |
| ------------- | --------------- | ----------- | ------------------------------- |
| String(Smart) | `02  +`         | String      | `02  {value}`                   |
| Regex         | `02 00 {value}` | String      | `02 0 40 09 21 FB 54 44 2D 18` |
| Vector        | `02 01 {value}` | String      | `02 1 40 09 21 FB 54 44 2D 18` |
| Hash_id       | `02 02 {value}` | String      | `02 2 40 09 21 FB 54 44 2D 18` |
| Uuid          | `02 03 {value}` | String      | `02 3 40 09 21 FB 54 44 2D 18` |
| Url           | `02 04 {value}` | String      | `02 4 40 09 21 FB 54 44 2D 18` |
| Email         | `02 05 {value}` | String      | `02 5 40 09 21 FB 54 44 2D 18` |
| Ip            | `02 06 {value}` | String      | `02 6 40 09 21 FB 54 44 2D 18` |
| Mac           | `02 07 {value}` | String      | `02 7 40 09 21 FB 54 44 2D 18` |
| Phone         | `02 08 {value}` | String      | `02 8 40 09 21 FB 54 44 2D 18` |
| Credit_card   | `02 09 {value}` | String      | `02 9 40 09 21 FB 54 44 2D 18` |

#### Objects
 Objects are a collection of key-value pairs. Each key-value pair is called a property. Properties are separated by commas, and the key and value in each property are separated by colons. Objects are surrounded by curly brackets.

| Type          | Hex Value       | Description | Example                         |
| ------------- | --------------- | ----------- | ------------------------------- |
| Object(Smart) | `03  +`         | Object      | `03  {value} 00 `               |
| Array(Smart)  | `04  +`         | Array       | `04  {value} 00 `               |
| Point         | `04 00 {value}` | Array       | `04 00 40 09 21 FB 54 44 2D 18` |
| Line          | `04 01 {value}` | Array       | `04 01 40 09 21 FB 54 44 2D 18` |
| Polygon       | `04 02 {value}` | Array       | `04 02 40 09 21 FB 54 44 2D 18` |
| Multipoint    | `04 03 {value}` | Array       | `04 03 40 09 21 FB 54 44 2D 18` |
| Multiline     | `04 04 {value}` | Array       | `04 04 40 09 21 FB 54 44 2D 18` |
| Multipolygon  | `04 05 {value}` | Array       | `04 05 40 09 21 FB 54 44 2D 18` |

#### Dates
Date and time data types are used for values that contain date and time. The following table lists the supported date and time data types.

| Type        | Hex Value       | Description | Example                         |
| ----------- | --------------- | ----------- | ------------------------------- |
| Date(Smart) | `05  +`         | Date        | `05  {value}`                   |
| Time        | `05 00 {value}` | Date        | `05 00 40 09 21 FB 54 44 2D 18` |
| DateTime    | `05 01 {value}` | Date        | `05 01 40 09 21 FB 54 44 2D 18` |
| Timestamptz | `05 02 {value}` | Date        | `05 02 40 09 21 FB 54 44 2D 18` |
| Duration    | `05 03 {value}` | Date        | `05 03 40 09 21 FB 54 44 2D 18` |
| Interval    | `05 04 {value}` | Date        | `05 04 40 09 21 FB 54 44 2D 18` |

#### Null & Boolean
Null is a special value that signifies no value. Comparing a value to null using the = operator is undefined. Instead, use WHERE IS NULL or WHERE IS NOT NULL.

| Type | Hex Value | Description | Example |
| ---- | --------- | ----------- | ------- |

| Null          | `06 `           | Null        | `06 `                           |
| Boolean       | `07  (00 or 01)`         | Boolean     | `07  01`                   |

#### JSON
JSON is a text format that is completely language independent but uses conventions that are familiar to programmers of the C-family of languages, including C, C++, C#, Java, JavaScript, Perl, Python, and many others. These properties make JSON an ideal data-interchange language.

| Type | Hex Value | Description | Example       |
| ---- | --------- | ----------- | ------------- |
| JSON | `08  +`   | JSON        | `08  {value}` |


#### Binary
Binary data types are used to store binary data or strings that contain binary data. The following table lists the supported binary data types.

| Type     | Hex Value       | Description | Example                         |
| -------- | --------------- | ----------- | ------------------------------- |
| Binary   | `09  +`         | Binary      | `09  {value}`                   |
| Image    | `09 60 {value}` | Binary      | `09 60 40 09 21 FB 54 44 2D 18` |
| Video    | `09 61 {value}` | Binary      | `09 61 40 09 21 FB 54 44 2D 18` |
| Audio    | `09 62 {value}` | Binary      | `09 62 40 09 21 FB 54 44 2D 18` |
| File     | `09 63 {value}` | Binary      | `09 63 40 09 21 FB 54 44 2D 18` |
| Document | `09 64 {value}` | Binary      | `09 64 40 09 21 FB 54 44 2D 18` |



#### Special
Special data types are used to store large amounts of data in a format optimized for storage. The following table lists the supported special data types.

| Type    | Hex Value       | Description | Example                         |
| ------- | --------------- | ----------- | ------------------------------- |
| Special | `0A  +`         | Special     | `0A  {value}`                   |
| Xml     | `0A 70 {value}` | Special     | `0A 70 40 09 21 FB 54 44 2D 18` |
| Yaml    | `0A 72 {value}` | Special     | `0A 72 40 09 21 FB 54 44 2D 18` |
| Toml    | `0A 73 {value}` | Special     | `0A 73 40 09 21 FB 54 44 2D 18` |
| Csv     | `0A 74 {value}` | Special     | `0A 74 40 09 21 FB 54 44 2D 18` |
| Tsv     | `0A 75 {value}` | Special     | `0A 75 40 09 21 FB 54 44 2D 18` |



## Page Structure

## Page Header(with explanation)
```
# Page Header start
00
# Encoding(01) UTF-8(01)
01 01
# Bon Version(02) 1.0.0(01 00 00)
02 01 00 00
# Revision(03) 35(23)
03 23
# Total Body Row Count(04) 1024(04 00)
04 04 00
# Total Body Size(05) 16KB(40 00)
05 40 00
# Compression Algorithm(06) None(00) zstd(01)
06 00
# Page Header end
00
```

## Cols Structure


## Row Structure