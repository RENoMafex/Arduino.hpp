#ifndef INCLUDED_ARDUINO_H
#define INCLUDED_ARDUINO_H

#include <iostream>
#include <chrono>
#include <thread>

namespace Arduino{
	inline void delay(int ms) {
		std::chrono::milliseconds milliseconds(ms);
		std::this_thread::sleep_for(milliseconds);
	}

	inline void delayMicroseconds(int µs) {
		std::chrono::microseconds microseconds(µs);
		std::this_thread::sleep_for(microseconds);
	}

	inline void delayNanoseconds(int ns) {
		std::chrono::nanoseconds nanoseconds(ns);
		std::this_thread::sleep_for(nanoseconds);
	}

	class Millis{
		public:
			inline Millis() {
				start_ = std::chrono::steady_clock::now();
			}

			auto operator()(){
				return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start_).count();
			}

		private:
			std::chrono::steady_clock::time_point start_;
	};

	class Micros{
		public:
			inline Micros() {
				start_ = std::chrono::steady_clock::now();
			}

			auto operator()(){
				return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - start_).count();
			}

		private:
			std::chrono::steady_clock::time_point start_;
	};

	class Nanos{
		public:
			inline Nanos() {
				start_ = std::chrono::steady_clock::now();
			}

			auto operator()(){
				return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::steady_clock::now() - start_).count();
			}

		private:
			std::chrono::steady_clock::time_point start_;
	};

	class SERIAL {
		public:
			SERIAL(const std::ostream& ostream) : os_(ostream){}

			template<typename T>
			inline void println(T any) {
				os_ << any << std::endl;
			}

			template<typename T>
			inline void print(T any) {
				os_ << any << std::flush;
			}

			template<typename T>
			inline void write(T any) {
				os_ << any;
			}

		private:
			const std::ostream& os_;
	};

	template<typename T>
	inline T abs(T x) {
		return x >= T(0) ? x : -x;
	}

	template<typename T>
	inline T max(T a, T b) {
		return a > b ? a : b;
	}

	template<typename T>
	inline T min(T a, T b) {
		return b > a ? a : b;
	}

	template<typename T>
	inline T constrain(T amt, T low, T high) {
		return amt < low ? low : (amt > high ? high : amt);
	}

	template<typename T>
	inline T round(T x) {
		return x >= T(0) ? T(x + T(0.5)) : T(x - T(0.5));
	}

	constexpr double PI         =  3.1415926535897932384626433832795;
	constexpr double HALF_PI    =  1.5707963267948966192313216916398;
	constexpr double TWO_PI     =  6.283185307179586476925286766559;
	constexpr double DEG_TO_RAD =  0.017453292519943295769236907684886;
	constexpr double RAD_TO_DEG = 57.295779513082320876798154814105;
	constexpr double EULER      =  2.718281828459045235360287471352;

	Millis millis;
	Micros micros;
	Nanos nanos;

	// stdout buffered
	SERIAL Serial(std::cout);

	// stderr unbuffered
	SERIAL Serial1(std::cerr);

	// stderr buffered
	SERIAL Serial3(std::clog);
}

#endif // #ifndef INCLUDED_ARDUINO_H