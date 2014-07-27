/*
IntWars playground server for League of Legends protocol testing
Copyright (C) 2012  Intline9 <Intline9@gmail.com>

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
#include "stdafx.h"
#include "Client.h"

ClientInfo::ClientInfo()
{
	keyChecked = false;
	ticks = 0;
	skinNo = 0;
	rank = "GOLD";
	team = TEAM_BLUE;
	champion = 0;
}

ClientInfo::~ClientInfo()
{
	delete champion;
	champion = 0;
}

void ClientInfo::setName(char *name)
{
	this->name = name;
}

void ClientInfo::setChampion(Champion* champion)
{
	this->champion = champion;
}

Champion* ClientInfo::getChampion() const { return champion; }

uint32 ClientInfo::getTicks()
{
	ticks++;
	return ticks;
}

void ClientInfo::setSkinNo(uint32 skinNo)
{
	this->skinNo = skinNo;
}