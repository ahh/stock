#include <cstdio>
#include <cassert>
#include <string>
#include <json/json.h>

using std::string;

const char key[] = "8aa84b1b171c9740a218abd8bbd6ba9068f62364";

void Buy(const string &acct, const string &exchange, const string &sym,
         const int shares, const int price) {
  Json::Value order;
  order["account"] = acct;
  order["venue"] = exchange;
  order["symbol"] = sym;
  order["price"] = price;
  order["qty"] = shares;
  order["direction"] = "buy";
  order["orderType"] = "limit";
  Json::FastWriter writer;
  string o = writer.write(order);
  printf("|%s|\n", o.c_str());
}

int main(int argc, char *argv[]) {
  assert(argc == 5);
  string acct = argv[1];
  string exchange = argv[2];
  string sym = argv[3];
  // not going to worry about price shifts for now
  const int price = atoi(argv[4]);
  for (int i = 0; i < 1000; ++i) {
    Buy(acct, exchange, sym, 100, price);
  }
  return 0;
}
