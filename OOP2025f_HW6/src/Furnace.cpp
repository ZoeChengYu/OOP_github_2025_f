#include "Furnace.hpp"

#include <stdexcept>

Furnace::Furnace() {

}
Furnace::~Furnace() {

}
void Furnace::SetInput(std::shared_ptr<ISmeltable> input) {
    input_ = input;
}
void Furnace::Smelt() {
    if (input_==nullptr||output_!=nullptr) {
        throw std::invalid_argument("Furnace::Smelt()");
    }
    output_=input_->Smelt();
    input_=nullptr;

}
std::shared_ptr<Ingot> Furnace::GetOutput() {
    if (output_==nullptr) {
        throw std::invalid_argument("Furnace::GetOutput()");
    }
    std::shared_ptr<Ingot> io_ =output_;
    output_=nullptr;
    return io_;
}