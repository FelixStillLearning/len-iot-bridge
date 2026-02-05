#pragma once
#include "../example_interface_model/example_interface_model.h"
#include "../example_abstract_model/example_abstract_model.h"

class ExampleModel : public ExampleAbstractModel, public ExampleInterfaceModel {
public:
    void print_example_interface_model() const override;
};
