#include <memory>
#include <stdexcept>

#include <catch2/catch.hpp>

#include "ecole/configuring.hpp"
#include "ecole/observation.hpp"

#include "conftest.hpp"

using namespace ecole;

TEST_CASE("Model creation") {
	auto env = configuring::Env<int, obs::BasicObs<>>(
		std::make_unique<obs::BasicObsFunction<>>(),
		std::make_unique<configuring::Configure<int>>("conflict/lpiterations"));

	for (auto i = 0L; i < 2; ++i) {
		env.reset(problem_file);
		env.step(0);
	}
}
