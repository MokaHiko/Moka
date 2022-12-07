#include <Moka.h>
#include <Core/Logger.h>
#include <Core/Asserts.h>

int main()
{
	MWARN("%s", "a warning");
	MINFO("%s", "knowledge");
	MDEBUG("%s", "debug");
	MERROR("%s", "oh no");
	MFATAL("%s", "oh no!");

	MASSERT_MSG(10 < 8, "just a test!");
}