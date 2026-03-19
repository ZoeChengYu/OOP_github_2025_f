#include "Order.hpp"

Order MakeOrder(std::vector<Ticket> tickets) {
    Order order;
    order.tickets = tickets;
    order.totalCount = 0;

    for (auto ticket : tickets) {
        order.totalCount+=CheckTicketPrice(ticket);
    }
    return order;
};
int CheckSpecificTicketSales(TicketType type,Order order) {
    int sum = 0;
    for (auto &ticket : order.tickets) {
        if (ticket.type == type) {
            sum+=CheckTicketPrice(ticket);
        }
    }
    return sum;
};