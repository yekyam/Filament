#include "Tester.hpp"
#include "Tests.hpp"

using namespace Tests;

int main()
{
	Tester tester;

	tester.add_test("Create Single Entity", test_create_single_entity);
	tester.add_test("Entity Existence", test_entity_exists);
	tester.add_test("Entity Limit", test_create_single_entity);
	tester.add_test("Add Component to Entity", test_add_mesh_component_to_entity);
	tester.add_test("No Dupe Components per Entity", test_add_duplicate_component_to_entity);
	tester.add_test("Succesfully marked component deleted", test_deleted_entity_components_are_gone);
	tester.add_test("Filament Init", test_filament_setup);
	// tester.add_test("Should fail", test_null_test); - null test, auto fails

	tester.run_all_tests();
}