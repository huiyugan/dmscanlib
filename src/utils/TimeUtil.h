#ifndef __INC_TIME_UTIL_H_
#define __INC_TIME_UTIL_H_

/*
Dmscanlib is a software library and standalone application that scans 
and decodes libdmtx compatible test-tubes. It is currently designed 
to decode 12x8 pallets that use 2D data-matrix laser etched test-tubes.
Copyright (C) 2010 Canadian Biosample Repository

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <string>
#include <sstream>

using namespace std;

#if defined (WIN32) && ! defined(__MINGW32__)
typedef time_t slTime;
#else
#include <sys/time.h>
typedef struct timeval slTime;
#endif

class Util {
public:
	static void getTime(slTime & tm);
	static void getTimestamp(std::string & str_r);
	static void difftiime(slTime & start, slTime & end, slTime & diff);

private:
};

template <typename T>
string to_string(T const& value) {
    stringstream sstr;
    sstr << value;
    return sstr.str();
}

#ifndef _VISUALC_
ostream & operator<<(ostream &os, slTime & tm);
#endif

#endif /* __INC_TIME_UTIL_H_ */
