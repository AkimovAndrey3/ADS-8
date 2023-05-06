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
  while (temp) {
    temp = temp->next;
    amount++;
    if (temp->light) {
      temp->light = false;
      countOp = amount * 2;
      for (int i = 0; i < amount; i++) {
        temp = temp->prev;
      }
      if (!temp->light) {
        return amount;
      }
    }
  }
}

int Train::getOpCount() {
  return countOp;
}
