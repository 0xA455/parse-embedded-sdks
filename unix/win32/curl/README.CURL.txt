The Parse.com embedded SDK depends on libcurl.

By default, the Visual Studio solutions assume that libcurl's headers and library files are in parse-embedded-sdks\unix\win32\curl.
For example, the directory listing might look something like this:
C:\>dir parse-embedded-sdks\unix\win32\curl
 Volume in drive C is Windows
 Volume Serial Number is 0000-0000

 Directory of C:\parse-embedded-sdks\unix\win32\curl

01/01/2015  01:00 PM    <DIR>          .
01/01/2015  01:00 PM    <DIR>          ..
01/01/2015  01:00 PM            90,205 curl.h
01/01/2015  01:00 PM            22,319 curlbuild.h
01/01/2015  01:00 PM             8,934 curlrules.h
01/01/2015  01:00 PM             3,075 curlver.h
01/01/2015  01:00 PM             3,472 easy.h
01/01/2015  01:00 PM           293,376 libcurl.dll
01/01/2015  01:00 PM             8,327 libcurl.exp
01/01/2015  01:00 PM            14,376 libcurl.lib
01/01/2015  01:00 PM             2,565 mprintf.h
01/01/2015  01:00 PM            15,992 multi.h
01/01/2015  01:00 PM                 0 README.CURL.txt
01/01/2015  01:00 PM             1,330 stdcheaders.h
01/01/2015  01:00 PM            37,557 typecheck-gcc.h
              13 File(s)        501,528 bytes