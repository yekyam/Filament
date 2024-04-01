#include "Tester.hpp"
#include "Tests.hpp"

using namespace Tests;

int main()
{
	Tester tester(4);

	tester.add_test("Create Single Entity", test_create_single_entity);
	tester.add_test("Entity Existence", test_entity_exists);
	tester.add_test("Entity Limit", test_create_single_entity);
	tester.add_test("Add Component to Entity", test_create_single_entity);
	tester.add_test("No Dupe Components per Entity", test_create_single_entity);
	// tester.add_test("Should fail", test_null_test); - null test, auto fails

	tester.run_all_tests();
}