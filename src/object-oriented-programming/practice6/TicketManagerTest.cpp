#include <gtest/gtest.h>
#include "Ticket.h"
#include "Person.h"

TEST(TicketManagerTest, itShouldNotBeEmpty)
{
    Ticket ticket;
    ASSERT_EQ(Ticket::getAmountOfAvailableTickets(), 1);
}

TEST(TicketManagerTest, itShouldReturnAvailable)
{
    Ticket ticket;
    stringstream s;
    s << ticket.getId() << "\t" << "AVAILABLE";
    ASSERT_EQ(ticket.toString(), s.str());
}

TEST(TicketManagerTest, itShouldReturnSoldWithPersonName)
{
    Ticket ticket;
    ASSERT_EQ(Ticket::getAmountOfAvailableTickets(), 1);
    ticket.sell();
    ASSERT_EQ(Ticket::getAmountOfAvailableTickets(), 0);
    ASSERT_EQ(Ticket::getAmountOfSoldTickets(), 1);
    stringstream s;
    s << ticket.getId() << "\t" << "A";
    ASSERT_EQ(ticket.toString(), s.str());
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}