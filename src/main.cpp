/***************************************************************************
 * MST Decoder/Encoder for Sonic '06                                       *
 * main.cpp: Main program.                                                 *
 *                                                                         *
 * Copyright (c) 2019 by David Korth.                                      *
 *                                                                         *
 * This program is free software; you can redistribute it and/or modify it *
 * under the terms of the GNU General Public License as published by the   *
 * Free Software Foundation; either version 3 of the License, or (at your  *
 * option) any later version.                                              *
 *                                                                         *
 * This program is distributed in the hope that it will be useful, but     *
 * WITHOUT ANY WARRANTY; without even the implied warranty of              *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the           *
 * GNU General Public License for more details.                            *
 *                                                                         *
 * You should have received a copy of the GNU General Public License       *
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.   *
 ***************************************************************************/

#include <stdlib.h>

#include <cerrno>
#include <cstdio>
#include <cstring>

#include <string>
#include <vector>
using std::string;
using std::vector;
using std::pair;

#include "tcharx.h"
#include "Mst.hpp"

int _tmain(int argc, TCHAR *argv[])
{
	if (argc != 2) {
		_ftprintf(stderr, _T("Syntax: %s mst_file.mst\n"), argv[0]);
		return EXIT_FAILURE;
	}

	Mst mst;
	int ret = mst.loadMST(argv[1]);
	if (ret != 0) {
		_ftprintf(stderr, _T("*** ERROR loading %s: %s\n"), argv[1], _tcserror(-ret));
		return EXIT_FAILURE;
	}

	// Dump the MST.
	mst.dump();

	return 0;
}