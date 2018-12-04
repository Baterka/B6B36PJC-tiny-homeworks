#pragma once

#include <memory>
#include <limits>

enum class generator_kind {
    random,
    mersenne,
    minstd
};


class numbers_generator {
public:

    size_t total_int = 0;
    size_t total_double = 0;
    size_t total_bool = 0;
    size_t total_false_bool = 0;
    size_t total_true_bool = 0;

    int min_int = std::numeric_limits<int>::max();
    int max_int = std::numeric_limits<int>::min();

    double min_double = std::numeric_limits<double>::max();
    double max_double = std::numeric_limits<int>::min();

    double random_double() {
        double d = random_double_impl();

        total_double++;

        if (d < min_double)
            min_double = d;
        if (d > max_double)
            max_double = d;

        return d;
    }

    int random_int(int lower, int upper) {
        int i = random_int_impl(lower, upper);

        total_int++;

        if (i < min_int)
            min_int = i;
        if (i > max_int)
            max_int = i;

        return i;
    }

    bool random_bool() {
        bool b = random_bool_impl();

        total_bool++;

        if (b)
            total_true_bool++;
        else
            total_false_bool++;

        return b;
    }

    virtual ~numbers_generator() = default;

    static std::unique_ptr<numbers_generator> create_by_kind(generator_kind kind, size_t seed);

    double min_generated_double() const { return min_double; }

    double max_generated_double() const { return max_double; }

    size_t doubles_generated() const { return total_double; }

    int min_generated_int() const { return min_int; }

    int max_generated_int() const { return max_int; }

    size_t ints_generated() const { return total_int; }

    size_t trues_generated() const { return total_true_bool; }

    size_t falses_generated() const { return total_false_bool; }

    size_t bools_generated() const { return total_bool; }

private:
    /**
     * Vygeneruje náhodné číslo v intervalu [0, 1)
     */
    virtual double random_double_impl() = 0;

    /**
     * Vygeneruje náhodné celé číslo v intervalu [lower, upper]
     */
    virtual int random_int_impl(int lower, int upper) = 0;

    /**
     * Vygeneruje náhodnou pravdivostní hodnotu (true/false)
     */
    virtual bool random_bool_impl() = 0;
};
