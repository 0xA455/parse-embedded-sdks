/*
 *  Copyright (c) 2015, Parse, LLC. All rights reserved.
 *
 *  You are hereby granted a non-exclusive, worldwide, royalty-free license to use,
 *  copy, modify, and distribute this software in source code or binary form for use
 *  in connection with the web services and APIs provided by Parse.
 *
 *  As with any software that integrates with the Parse platform, your use of
 *  this software is subject to the Parse Terms of Service
 *  [https://www.parse.com/about/terms]. This copyright notice shall be
 *  included in all copies or substantial portions of the software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 *  FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 *  COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 *  IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 *  CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */

#include<ctype.h>
#include<stdlib.h>
#include<string.h>

#include <Rpc.h>
#pragma comment(lib, "Rpcrt4")

void parseGetUUID(char *id, size_t id_size) {
    size_t i = 0;
	UUID uuid;
	char *uuid_string;
	UuidCreate(&uuid);
	UuidToStringA(&uuid, &uuid_string);

    strncpy_s(id, id_size, uuid_string, _TRUNCATE);
	i = 0;
    for ( ; i < strlen(id) ; i++) {
        id[i] = tolower(id[i]);
    }

	RpcStringFreeA(&uuid_string);
}
