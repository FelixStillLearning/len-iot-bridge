#include "models/example_model/example_model.h"
#include <memory>

int main() {
    ExampleModel concrete_model;
    concrete_model.print_example_abstract_model();

    const ExampleInterfaceModel& example_ref = concrete_model;
    example_ref.print_example_interface_model();

    return 0;
}
