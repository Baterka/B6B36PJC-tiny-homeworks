#include "tiny-05.hpp"

namespace pjc {

    complex::complex(double real, double imaginary) :
            m_real(real),
            m_imag(imaginary) {}

    double complex::real() const {
        return m_real;
    }

    void complex::real(double d) {
        m_real = d;
    }

    double complex::imag() const {
        return m_imag;
    }

    void complex::imag(double d) {
        m_imag = d;
    }

    complex complex::operator+(const complex &c) const {
        return complex(m_real + c.m_real, m_imag + c.m_imag);
    }

    complex complex::operator+(const double d) const {
        return complex(m_real + d, m_imag);
    }

    complex operator+(double d, const complex &c) {
        return complex(d + c.m_real, c.m_imag);
    }

    complex complex::operator-(const complex &c) const {
        return complex(m_real - c.m_real, m_imag - c.m_imag);
    }

    complex complex::operator-(const double d) const {
        return complex(m_real - d, m_imag);
    }

    complex operator-(double d, const complex &c) {
        return complex(d - c.m_real, -c.m_imag);
    }

    complex complex::operator*(const complex &c) const {
        return complex((m_real * c.m_real) - (m_imag * c.m_imag), (m_real * c.m_imag) + (m_imag * c.m_real));
    }

    complex complex::operator*(const double d) const {
        return complex(m_real * d, m_imag * d);
    }

    complex operator*(double d, const complex &c) {
        return complex(d * c.m_real, d * c.m_imag);
    }
}
