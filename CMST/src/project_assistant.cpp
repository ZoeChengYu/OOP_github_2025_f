#include "project_assistant.hpp"

#include <stdexcept>

#include "staff.hpp"
#include "staff_no.hpp"
#include "title.hpp"

ProjectAssistant::ProjectAssistant(std::string name, std::string phone, int ext, StaffLevel level):Staff(name,Title::PROJECT_ASSISTANT,phone,ext,StaffNo::N,level) {
    if (ext<0) {
        throw std::invalid_argument("");
    }
}
