/*************************************************************

 file: CameraData.h
 author: E.C. Shin
 begin: March 13 2013
 copyright: (c) 2012 KITECH, OPRoS
 email: uncholshin@gmail.com

***************************************************************

OPRoS source code is provided under a dual license mode:
 LGPL and OPRoS individually.

LGPL: You can redistribute it and/or modify it under the terms
 of the Less GNU General Public License as published by the Free
 Software Foundation, either version 3 of the License.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of 
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the 
 Less GNU General Public License for more details. 

 You should have received a copy of the Less GNU General Public
 License along with this program. If not, see 
 <http://www.gnu.org/licenses/>.

OPRoS individual license: An individual license is a license for
 modifying the source code of OPRoS and distiributing it in a
 closed format for commercial purposes.

 If you are interested in this option, please see 
 <http://www.opros.or.kr>.

This license policy may be changed without prior notice.

***************************************************************/

#pragma once

#include "ApiTypes.h"

namespace OPRoS
{

class CameraData
{
public:
	CameraData(void) {
		status = OPROS_SUCCESS;
	}
	CameraData(int32_t format, int32_t width, int32_t, std::vector<uint8_t> &data) {
		status = OPROS_SUCCESS;
		this->format = format;
		this->width = width;
		this->height = height;
		this->data = data;
	}
	virtual ~CameraData(void) {
	}

	ReturnType status;
	int32_t	format;
	int32_t width;
	int32_t height;
	std::vector<uint8_t> data;

	void save(opros::archive::oarchive &ar, const unsigned int)
	{
		ar << status;
		ar << format;		ar << width;
		ar << height;			ar << data;
	}

	void load(opros::archive::iarchive &ar, const unsigned int)
	{
		ar >> status;
		ar >> format;		ar >> width;
		ar >> height;		ar >> data;
	}

	CameraData operator=(const CameraData &arg)
	{
		this->status = arg.status;
		this->format = arg.format;
		this->width = arg.width;
		this->height = arg.height;
		this->data = arg.data;

		return *this;
	}
};
inline std::string typeName(CameraData *p)	{ return "CameraData"; }

}