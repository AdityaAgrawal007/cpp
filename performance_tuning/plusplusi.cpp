int main() {
  for (int i = 0; i < 5; i++) {
  } // it first creates a copy of i then increments it and then returns it but
    // the loop ignores the value returned by the compiler (which is that old
    // value) and it actually directly access the new value (incremented value
    // by the compiler) and uses it here all of this happens cause c++ lang says
    // that post increment the value of the variable should be different so the
    // coplier is obliged to do this
  for (int i = 0; i < 5; ++i) {
  } // this just increments it and returns, compiler doesn't have any
    // obligations here though
}
