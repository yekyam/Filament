#include "Tester.hpp"
#include "Tests.hpp"

using namespace Tests;

int main()
{
	Tester tester;

	tester.add_test(STRINGIFY(test_create_single_entity), test_create_single_entity);
	tester.add_test(STRINGIFY(test_create_single_entity), test_create_single_entity);
	tester.add_test(STRINGIFY(test_entity_exists), test_entity_exists);
	tester.add_test(STRINGIFY(test_create_single_entity), test_create_single_entity);
	tester.add_test(STRINGIFY(test_add_mesh_component_to_entity), test_add_mesh_component_to_entity);
	tester.add_test(STRINGIFY(test_add_duplicate_component_to_entity), test_add_duplicate_component_to_entity);
	tester.add_test(STRINGIFY(test_deleted_entity_components_are_gone), test_deleted_entity_components_are_gone);
	tester.add_test(STRINGIFY(test_filament_setup), test_filament_setup);
	// tester.add_test("Should fail", test_null_test); - null test, auto fails

	tester.run_all_tests();
}