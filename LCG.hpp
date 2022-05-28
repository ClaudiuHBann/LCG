#pragma once

#include <stdint.h>
#include <time.h>

/**
 * Implementation of LCG (Linear Congruential Generator)[https://en.wikipedia.org/wiki/Linear_congruential_generator]
 */
class LCG {
public:
	/**
	* Default constructor with the default parameter as the timestamp from 1970 in seconds
	*
	* @param[in] seed the root from which the numbers will generate
	*/
	LCG(const int64_t seed = time(nullptr)) {
		SetSeed(seed);
	}

	/**
	* Default destructor
	*/
	~LCG() {}

	/**
	* Sets the seed of the lcg
	*
	* @param[in] seed the root from which the numbers will generate
	*/
	inline void SetSeed(const int64_t seed) {
		this->m_seed = seed;
		m_previous = (uint32_t)seed;
	}

	/**
	* Retrieves the seed of the lcg
	*
	* @return the seed of the lcg
	*/
	inline int64_t GetSeed() const {
		return m_seed;
	}

	/**
	* Generates the next random number
	*
	* @return the next random number
	*/
	inline uint32_t Next() {
		return m_previous = (m_a * m_previous + m_c) % m_m;
	}

	/**
	* Generates the next random number
	*
	* @param[in] min the minimum number to randomly generate
	* @param[in] max the maximum number to randomly generate (+-1 depends on 'include')
	* @param[in] include with or without the 'max'
	*
	* @return the next random number
	*/
	inline uint32_t Next(const uint32_t min, const uint32_t max, const bool include = false) {
		return Next() % (max - min + include) + min;
	}

private:
	int64_t m_seed = 0; ///< the seed of the lcg

	static uint32_t m_a, m_c, m_m; ///< MSVC C++ LCG constants
	uint32_t m_previous = 0; ///< last randomly generated number
};

uint32_t LCG::m_a = 214013, LCG::m_c = 2531011, LCG::m_m = UINT32_MAX;