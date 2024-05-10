/* 


* This file is part of the BON library.

Page Header (Start of 0x00, endof 0x00)
Encoding: 0x01 0x(UTF-8 hex value)
Bon Version: 0x02 0x(Version hex value)
Revision: 0x03 0x(Revision hex value)
Total Body Row Count: 0x04 0x(Count hex value)
Total Body Size: 0x05 0x(Size hex value)
Compression Algorithm: 0x06 0x(Algorithm hex value) (is Compressed 0x01, is not compressed 0x00)

Row x: 0x(row start cursor hex value) 0x(row end cursor hex value) 

Page Map (Page Body Row map) (Start of 0x00, endof 0x00)


Page Structure
ColName |   BON Tip Bayrağı |	Veri Tipi/Alt veri tipi | Değer(4 digit hex)
#1          0x01	            Number
                                    0x010 integer                 0x07B5 
                                    0x011 float                   
                                    0x012 double
                                    0x013 long
                                    0x014 hexadecimal
            0x02	            String
                                    0x020 regex
                                    0x021 vector
                                    0x022 hash_id
                                    0x023 uuid
                                    0x024 url
                                    0x025 email
                                    0x026 ip
                                    0x027 mac
                                    0x028 phone
                                    0x029 credit_card
            0x03	            Object
            0x04	            Array
                                    0x040 point
                                    0x041 line
                                    0x042 polygon
                                    0x043 multipoint
                                    0x044 multiline
                                    0x045 multipolygon
            0x05	            Date
                                    0x050 Time // hh::mm::ss(hex value)
                                    0x051 DateTime // yyyy::mm::dd::hh::mm::ss(hex value)
                                    0x052 Timestamptz // yyyy::mm::dd::hh::mm::ss::msZ(hex value) 
                                    0x053 Duration/Interval // 1 year 2 month 3 day 4 hour 5 minute 6 second(hex value)
            0x06        	Null
            0x07        	True
            0x08        	False
            0x00        	Object/Array End

Page Data Source
- ...(Ordered Row values)
- ...(Ordered Row values)
...                 
 */

#pragma once
#include <deque>
#include <string_view>

namespace bon {

enum struct PageHead_Types {
  kEncoding = 0x01,  // UTF-8
  kBonVersion = 0x02,
  kRevision = 0x03,
  kTotalBodyRowCount = 0x04,
  kTotalBodySize = 0x05,
  kCompressionAlgorithm = 0x06,
  kCustomHeader = 0x07,
};

enum struct Dictionary_Data_Types {
  // Numeric Types
  kNumber = 0x01,             // binary 0000 0001
  kNumberInteger = 0x10,      // binary 0000 0001 0000
  kNumberBigint = 0x11,       // binary 0000 0001 0011
  kNumberFloat = 0x12,        // binary 0000 0001 0001
  kNumberDouble = 0x13,       // binary 0000 0001 0010
  kNumberHexadecimal = 0x14,  // binary 0000 0001 0100
  // String Types
  kString = 0x02,            // binary 0000 0010
  kStringRegex = 0x20,       // binary 0000 0010 0000
  kStringVector = 0x21,      // binary 0000 0010 0001
  kStringHashId = 0x22,      // binary 0000 0010 0010
  kStringUuid = 0x23,        // binary 0000 0010 0011
  kStringUrl = 0x24,         // binary 0000 0010 0100
  kStringEmail = 0x25,       // binary 0000 0010 0101
  kStringIp = 0x26,          // binary 0000 0010 0110
  kStringMac = 0x27,         // binary 0000 0010 0111
  kStringPhone = 0x28,       // binary 0000 0010 1000
  kStringCreditCard = 0x29,  // binary 0000 0010 1001
  // Object Types
  kObject = 0x03,  // binary 0000 0011
  // Array Types
  kArray = 0x04,              // binary 0000 0100
  kArrayPoint = 0x40,         // binary 0000 0100 0000
  kArrayLine = 0x41,          // binary 0000 0100 0001
  kArrayPolygon = 0x42,       // binary 0000 0100 0010
  kArrayMultiPoint = 0x43,    // binary 0000 0100 0011
  kArrayMultiLine = 0x44,     // binary 0000 0100 0100
  kArrayMultiPolygon = 0x45,  // binary 0000 0100 0101
  // Date Types
  kDate = 0x05,         // binary 0000 0101
  kDateTime = 0x50,     // binary 0000 0101 0000
  kTime = 0x51,         // binary 0000 0101 0001
  kTimestampTz = 0x52,  // binary 0000 0101 0010
  kDuration = 0x53,     // binary 0000 0101 0011
  // Null Types
  kNull = 0x06,  // binary 0000 0110
  // Boolean Types
  kTrue = 0x07,
  kFalse = 0x08,
  kBlockEnd = 0x00,
};

}  // namespace bon