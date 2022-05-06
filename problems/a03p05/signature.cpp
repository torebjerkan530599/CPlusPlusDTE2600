#include "header.h"
#include <iostream>
#include <vector>

// The <signature> function definition(s)
std::string toHtmlHex(ColorName color_name)
{
	switch (color_name)
	{
	case ColorName::Red:
		return "ff0000";
	case ColorName::Green:
		return "00ff00";
	case ColorName::Blue:
		return "0000ff";
	case ColorName::LightYellow: //== Yellow??
		return "ffffed";
	case ColorName::Brown:
		return "a52a2a";
	case ColorName::Pink:
		return "ffc0cb";
	case ColorName::Orange:
		return "ffa500";
	case ColorName::Purple:
		return "800080";
	case ColorName::White:
		return "ffffff";
	case ColorName::Black:
		return "000000";
	default:
		return "";
	}
}

Color toColor(ColorName color_name)
{
	Color c;

	switch (color_name)
	{

	case ColorName::Red:
		c.r = 255;
		c.g = 0;
		c.b = 0;
		break;
	case ColorName::Green:
		c.r = 0;
		c.g = 255;
		c.b = 0;
		break;
	case ColorName::Blue:
		c.r = 0;
		c.g = 0;
		c.b = 255;
		break;
	case ColorName::LightYellow:
		c.r = 255;
		c.g = 255;
		c.b = 237;
		break;
	case ColorName::Brown:
		c.r = 165;
		c.g = 42;
		c.b = 42;
		break;
	case ColorName::Pink:
		c.r = 255;
		c.g = 192;
		c.b = 203;
		break;
	case ColorName::Orange:
		c.r = 255;
		c.g = 165;
		c.b = 0;
		break;
	case ColorName::Purple:
		c.r = 128;
		c.g = 0;
		c.b = 128;
		break;
	case ColorName::White:
		c.r = 255;
		c.g = 255;
		c.b = 255;
		break;
	case ColorName::Black:
		c.r = 0;
		c.g = 0;
		c.b = 0;
		break;
	default:
		break;
	}

	return c;
}

// Den andre feilen om at short og Flag ikke kan sammenliknes er fordi Flags ikke er short men en bruker - 
// definert type som inneholder en short.Og kompilatoren er strict.
// Dere kan bruke static_cast til å oversette verdier.
// Dere bruke static_cast til å oversette fra Flag::Flag1 til en short:
// auto const a = static_cast<Flags>(Flag::Flag1);
// Dere kan også lage en ny short(eller Flags) ved å gi flagge direkte til konstruktøren til short(eller Flags).
// Flags(Flag::Flag1)

std::string toString(Flags flags)
{
		
		std::string str = "";

		if (static_cast<Flags>(Flag::Flag1) & flags)
			str += "flag1|";
		if (static_cast<Flags>(Flag::Flag2) & flags)
			str += "flag2|";
		if (static_cast<Flags>(Flag::Flag3) & flags)
			str += "flag3|";
		if (static_cast<Flags>(Flag::Flag4) & flags)
			str += "flag4|";
		if (static_cast<Flags>(Flag::Flag5) & flags)
			str += "flag5|";
		if (static_cast<Flags>(Flag::Flag6) & flags)
			str += "flag6|";
		if (static_cast<Flags>(Flag::Flag7) & flags)
			str += "flag7|";
		if (static_cast<Flags>(Flag::Flag8) & flags)
			str += "flag8|";

		str = str.substr(0, str.size() - 1);


	switch (flags)
	{
		case (static_cast<Flags>(Flag::Flag1)): //1
			str += "flag1|";
		case (static_cast<Flags>(Flag::Flag2)): //2
			str += "flag2|";
		case (static_cast<Flags>(Flag::Flag3)): //4
			str += "flag3|";
		case (static_cast<Flags>(Flag::Flag4)): //8
			str += "flag4|";
		case (static_cast<Flags>(Flag::Flag5)): //16
			str += "flag5|";
		case (static_cast<Flags>(Flag::Flag6)): //32
			str += "flag6|";
		case (static_cast<Flags>(Flag::Flag7)): //64
			str += "flag7|";
		case (static_cast<Flags>(Flag::Flag8)): //133
			str += "flag8";
		default:
			break;
	}
	return str;
}

	
