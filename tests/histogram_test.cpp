#include <catch2/catch_test_macros.hpp>

#include <hdr/hdr_histogram.h>

TEST_CASE("HdrHistogram records values and reports percentiles", "[smoke]") {
  hdr_histogram* histogram = nullptr;
  REQUIRE(hdr_init(1, 1'000'000, 3, &histogram) == 0);

  for (int value = 1; value <= 1000; ++value) {
    REQUIRE(hdr_record_value(histogram, value));
  }

  CHECK(hdr_total_count(histogram) == 1000);
  CHECK(hdr_values_are_equivalent(histogram, hdr_value_at_percentile(histogram, 50.0), 500));

  hdr_close(histogram);
}
