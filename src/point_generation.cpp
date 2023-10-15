#include "point_generation.hh"

double get_random_double(double min, double max) {
    random_device device;
    mt19937 rng(device());
    uniform_real_distribution<double> rndom(min, max);
    return rndom(rng);
}

int get_random_int(int min, int max) {
    random_device device;
    mt19937 rng(device());
    uniform_int_distribution<int> rndom(min, max);
    return rndom(rng);
}

vector<double> generate_point(int k) {
    vector<double> v(k);
    for (int i = 0; i < k; ++i) v[i] = get_random_double(0.0, 1.0);
    return v;
}
