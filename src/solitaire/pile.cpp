#include "pile.h"
 
Pile::Pile() {
  _count = 0;
}

void Pile::addCard(Card card) {
  if (_count < MAX_PILE) _cards[_count++] = card;
}

byte Pile::getCardCount() const {
  return _count;
}

Card Pile::getCard(int indexFromTop) const {
  if (indexFromTop < _count) {
    return _cards[_count - indexFromTop - 1];
  }
  return Card(two, heart, false);
}

Card Pile::removeTopCard() {
  if (_count > 0) return _cards[--_count];
  return Card();
}

void Pile::removeCards(int count, Pile* destination) {
  count = min(count, _count);
  _count -= count;
  for (int i = 0; i < count; i++) destination->addCard(_cards[_count + i]);
}

void Pile::empty() {
  _count = 0;
}

void Pile::shuffle() {
  for (int i = 0; i < _count; i++) {
    int randomIndex = random(_count - i);
    Card tmp = _cards[randomIndex];
    _cards[randomIndex] = _cards[_count - i - 1];
    _cards[_count - i - 1] = tmp;
  }
}

void Pile::newDeck() {
  empty();
  for (int suit = spade; suit <= diamond; suit++) {
    for (int value = ace; value <= king; value++) {
      addCard(Card(static_cast<Value>(value), static_cast<Suit>(suit), true));
    }
  }
}