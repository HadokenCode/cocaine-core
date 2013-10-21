/*
    Copyright (c) 2011-2013 Andrey Sibiryov <me@kobology.ru>
    Copyright (c) 2011-2013 Other contributors as noted in the AUTHORS file.

    This file is part of Cocaine.

    Cocaine is free software; you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation; either version 3 of the License, or
    (at your option) any later version.

    Cocaine is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef COCAINE_IO_DISPATCH_MAPS_HPP
#define COCAINE_IO_DISPATCH_MAPS_HPP

#include "cocaine/common.hpp"

namespace cocaine {

struct dispatch_maps_t:
    public std::map<int, std::tuple<std::string, dispatch_maps_t>>
{
    typedef std::map<
        int,
        std::tuple<std::string, dispatch_maps_t>
    > mapping_type;

    dispatch_maps_t(): mapping_type() { }
    dispatch_maps_t(const dispatch_maps_t& o): mapping_type(o) { }
    dispatch_maps_t(dispatch_maps_t&& o): mapping_type(std::move(o)) { }

    dispatch_maps_t& operator=(const dispatch_maps_t& lhs) {
        static_cast<mapping_type&>(*this) = lhs; return *this;
    }

    dispatch_maps_t& operator=(dispatch_maps_t&& lhs) {
        static_cast<mapping_type&>(*this) = std::move(lhs); return *this;
    }
};

} // namespace cocaine

#endif
