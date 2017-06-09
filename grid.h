enum class CoordinateSystem {Cylindrical, Spherical};

template<CoordinateSystem coords>
class Grid
{
    Grid(const std::vector<float> & a,
         const std::vector<float> & b,
         const std::vector<float> & c)
        : a(a), b(b), c(c)
    {
        // Nothing to do here.
    }

    void draw()
    {
        for (float x : a) {
            for (float y : b) {
                draw_line<2, coords>(c.front(), c.back());
            }
        }
        for (float x : b) {
            for (float y : c) {
                draw_line<0, coords>(a.front(), a.back());
            }
        }
        for (float x : a) {
            for (float y : c) {
                draw_line<1, coords>(b.front(), c.back());
            }
        }
    }
};
