// Copyright 2021 NNTU-CS
#include "train.h"

void Train::addCage(bool light) {
  if (!head) {
    Cage* item = new Cage;
    item->light = light;
    head = item;
    tail = item;
  } else {
    Cage* item = new Cage;
    item->light = light;
    tail->next = item;
    item->prev = tail;
    tail = item;
  }
  tail->next = head;
  head->prev = tail;
}

int Train::getLength() {
  Cage* temp = head;
  temp->light = true;
  while (true) {
    temp = temp->next;
    amount++;
    if (temp->light) {
      temp->light = false;
      for (int i = 0; i < amount; i++) {
        temp = temp->prev;
      }
      countOp += amount * 2;
      if (!temp->light) {
        return amount;
      }
      amount = 0;
    }
  }
  return 0;
}

int Train::getOpCount() {
  return countOp;
}
