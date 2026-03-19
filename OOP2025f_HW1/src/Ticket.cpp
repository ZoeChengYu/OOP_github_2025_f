#include "Ticket.hpp"
#include <stdexcept>

Ticket MakeTicketOrder(TicketType type) {
    Ticket ticket;
    ticket.type = type;
    switch (type) {
    case TicketType::First:
        ticket.count=450;
        break;
    case TicketType::Business:
        ticket.count=325;
        break;
    case TicketType::Economy:
        ticket.count=200;
        break;
    default:
        throw std::invalid_argument("");
    }
    return ticket;
};

int CheckTicketPrice(Ticket ticket) {
    switch (ticket.type) {
        case TicketType::First:
            if (ticket.count != 450) throw std::invalid_argument("");
            return 450;
        case TicketType::Business:
            if (ticket.count != 325)throw std::invalid_argument("");
            return 325;
        case TicketType::Economy:
            if (ticket.count != 200) throw std::invalid_argument("");
            return 200;
        default:
            throw std::invalid_argument("");
    }
};