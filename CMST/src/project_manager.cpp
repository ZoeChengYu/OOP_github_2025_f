#include "project_manager.hpp"

#include <stdexcept>

#include "staff.hpp"
#include "staff_no.hpp"

ProjectManager::ProjectManager(std::string name, std::string phone, int ext, StaffLevel level):Staff(name,Title::PROJECT_MANAGER,phone,ext,StaffNo::M,level){
    if (ext<0) {
        throw std::invalid_argument("");
    }
}
