#pragma once
#include "IP6Packet.h"
#include "Packet.h"

bool operator==(const ip_address addr1, const ip_address addr2)//cleaner implementation of the above function done in a single check
{
	if (addr1.byte1 == addr2.byte1 && addr1.byte2 == addr2.byte2 && addr1.byte3 == addr2.byte3 && addr1.byte4 == addr2.byte4)
	{
		return true;
	}
	return false;
}
bool operator==(const ip6_address addr1, const ip6_address addr2)//cleaner implementation of the above function done in a single check
{
	if (addr1.byte1 == addr2.byte1 && addr1.byte2 == addr2.byte2 && addr1.byte3 == addr2.byte3 && addr1.byte4 == addr2.byte4 && addr1.byte5 == addr2.byte5
	   && addr1.byte6 == addr2.byte6 && addr1.byte7 == addr2.byte7 && addr1.byte8 == addr2.byte8 && addr1.byte9 == addr2.byte9 && addr1.byte10 == addr2.byte10
	   && addr1.byte11 == addr2.byte12 && addr1.byte13==addr2.byte13 && addr1.byte14 == addr2.byte14 && addr1.byte15 == addr2.byte15 
	   && addr1.byte16 == addr2.byte16)
	{
		return true;
	}
	return false;
}
