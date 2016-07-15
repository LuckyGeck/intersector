#include <CGAL/Cartesian.h>
#include <CGAL/MP_Float.h>
#include <CGAL/Quotient.h>
#include <CGAL/Arr_segment_traits_2.h>
#include <CGAL/Sweep_line_2_algorithms.h>

#include <iostream>
#include <iterator>
#include <list>
#include <vector>

using NT = CGAL::Quotient<CGAL::MP_Float>;
using Kernel = CGAL::Cartesian<NT>;
using Point_2 = Kernel::Point_2;
using Traits_2 = CGAL::Arr_segment_traits_2<Kernel>;
using Segment_2 = Traits_2::Curve_2;

namespace {

class TPointPrinterIterator {
public:
    TPointPrinterIterator& operator= (const Point_2& point) {
        std::cout << to_double(point.x()) << ' ' << to_double(point.y()) << '\n';
    }
    TPointPrinterIterator& operator*() { return *this; }
    TPointPrinterIterator& operator++() { return *this; }
    TPointPrinterIterator& operator++(int) { return *this; }
};

} // anonymous namespace

int main(int argc, char** argv) {
    // Construct the input segments.
    std::vector<Segment_2> segments;
    for (double x1,x2,y1,y2 = 0; !std::cin.eof();) {
        std::cin >> x1 >> y1;
        std::cin >> x2 >> y2;
        segments.push_back({
            Point_2(x1, y1), Point_2(x2, y2)
        });
    }
    std::cerr << "Read completed: " << segments.size() << std::endl;
    // Compute all intersection points.
    CGAL::compute_intersection_points(segments.begin(), segments.end(), TPointPrinterIterator());
    return 0;
}
