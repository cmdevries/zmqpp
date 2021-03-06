#pragma once

#include <cstdint>
#include <iostream>

namespace zmqpp
{

    /**
     * Signal is a 8 bytes integer. 7 first bytes acts as a magic number so we can distinguish signal
     * from other message. The last byte is the signal's value.
     */
    enum class signal : int64_t
    {
	/**
	 * Only 7 bytes matter here
	 */
	header = 0x0077665544332211L,
	/**
	 * Indicates a success.
	 */
	ok = (header << 8) | 0x00,
	/**
	 * Indicates an error.
	 */
	ko = (header << 8) | 0x01,
	/**
	 * Indicates a request to stop. This is used from parent thread to child within the actor class
	 */
	stop = (header << 8) | 0x02,

	test = (header << 8) | 0xFF
    };

}


namespace std
{
    /**
     * Write the value of the signal to the stream without removing the signal header..
     */
    ostream &operator<<(ostream &s, const zmqpp::signal &sig);
}
