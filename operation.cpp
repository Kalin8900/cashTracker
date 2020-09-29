#include "operation.h"


Operation::Operation(const float &value, const QDateTime &date,
                     const QString &category, QObject *parent)
    : QObject(parent),
      value_(value),
      date_(date),
      category_(category) {}
