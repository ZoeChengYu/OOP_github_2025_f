#include "Ingot.hpp"
Ingot::Ingot(Material material):type_(material) {

}

Material Ingot::GetMaterial() const {
    return type_;
}

Ingot::~Ingot() {

}