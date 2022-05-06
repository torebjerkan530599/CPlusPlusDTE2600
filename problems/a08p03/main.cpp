#include <ranges>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <iomanip>
/************************************
 * Types, declarations and prototypes
 */

namespace sr = std::ranges;
namespace sv = std::views;


struct Person {
    std::string name;
};

struct AccountInfo {
    std::string name;
    double      balance;
    size_t      owner_id;
};

struct Transaction {
    size_t issuer_id;
    size_t account_id_from;
    size_t account_id_to;
        double amount;
};

using PeopleMap = std::unordered_map<size_t, Person>;
using AccountMap = std::unordered_map<size_t, AccountInfo>;
using TransactionVector = std::vector<Transaction>;


void printAccountInfo(std::ostream& stream, AccountMap const& ainfo_map,
    PeopleMap const& pinfo_map);
void printTransactions(std::ostream& stream, TransactionVector const& transactions, 
    PeopleMap const& pmap,
    AccountMap const& ainfo_map);


void printAmount(std::ostream& stream, double amount);


/******
 * Main
 */

 // The main function is the entry point for any program written in C++
int main(int /*argc*/, char** /*argv*/)
{
    std::string audit_type;
    std::cin >> audit_type; //input type of audit

    // clear
    PeopleMap         people;
    AccountMap        accounts;
    TransactionVector transactions;

    // Load people data
    int no_people;
    std::cin >> no_people; //how many people
    sr::for_each(sv::iota(0, no_people), [&](auto const&) {
        int    id;
        Person in;
        std::cin >> id >> in.name; //store id and name about people
        people[id] = in;
        });

    // Load bank account data
    int no_accounts;
    std::cin >> no_accounts; //how many accounts does this concern
    sr::for_each(sv::iota(0, no_accounts), [&](auto const&) {
        int         id;
        AccountInfo in;
        std::cin >> id >> in.name >> in.balance >> in.owner_id; //enter the details of each account
        accounts[id] = in;
        });

    // Load transactions
    int no_transactions;
    std::cin >> no_transactions; //how many transactions
    sr::for_each(sv::iota(0, no_transactions), [&](auto const&) {
        Transaction in;
        std::cin >> in.issuer_id >> in.account_id_from >> in.account_id_to >> in.amount; //enter "utsteder","fra" "til" og "sum"
        transactions.push_back(in);
        });


    auto audit_balance_before = double{ 0.0 };
    auto audit_balance_after = double{ 0.0 };

    // Audit printing
    if (audit_type == "account_info_pre")
        printAccountInfo(std::cout, accounts, people);
    else if (audit_type == "transactions")
        printTransactions(std::cout, transactions, people , accounts);

    // Sum accounts before
    for (auto const& [aid, ainfo] : accounts)
        audit_balance_before += ainfo.balance;

    // Apply transactions
    for (auto const& [pid, aid_from, aid_to, am] : transactions) {
        // Apply
        accounts.at(aid_from).balance -= am;   // withdraw //debugged, changed sign
        accounts.at(aid_to).balance += am;     // deposite //debugged, changed sign
    }

    // Sum accounts after
    for (auto const& [aid, ainfo] : accounts)
        audit_balance_after += ainfo.balance; //debugged, added +sign

    // Audit balance
    auto const balance_audit = audit_balance_after - audit_balance_before;

    // Audit printing
    if (audit_type == "account_info_post")
        printAccountInfo(std::cout, accounts, people);
    else if (audit_type == "balance")
        printAmount(std::cout, balance_audit);

    // Return the value Zero to the operating system
    // Indicating that your program terminated successfully without sideeffects
    return 0;
}


/*****************
 * Implementations
 */

void printAccountInfo(std::ostream& stream, AccountMap const& ainfo_map,
    PeopleMap const& pinfo_map)
{
    for (auto const& [aid, ainfo] : ainfo_map) {
        auto const& [name, balance, owner_id] = ainfo;
        auto const& owner_name = pinfo_map.at(owner_id).name;
        stream << aid << ' ' << name << ' ' << owner_name << ' ';
        printAmount(stream, balance);
        stream << '\n';
    }
}

void printTransactions(std::ostream& stream,
    TransactionVector const& transactions,
    PeopleMap const& pinfo_map, AccountMap const& ainfo_map)
{

    for (auto const& [pid, aid_from, aid_to, am] : transactions) {
        auto const& issuer = pinfo_map.at(pid).name;
        auto const& from_account = ainfo_map.at(aid_from).name;
        auto const& to_account = ainfo_map.at(aid_to).name;

        stream << from_account << ' ' << to_account << ' ';
        printAmount(stream, am);
        stream << ' ' << issuer << '\n';
    }
}

void printAmount(std::ostream& stream, double amount)
{
    std::cout << std::fixed << std::showpoint << std::setprecision(2) << amount;
}
