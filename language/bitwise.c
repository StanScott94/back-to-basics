#include <stdio.h>

#define VERIFY(s, i) (printf("%s %s", s, (i) ? "successful\n" : "failed\n"))

int bitwiseNot() {
    int onesCompliment = -0b0101 - 1 == ~0b0101;
    int twosCompliment = -0b0101 == ~0b0101 + 1;
    return onesCompliment && twosCompliment;
}

int bitwiseAnd() {
    return 0b0001 == (0b0101 & 0b0011);
}

int bitwiseOr() {
    return 0b0111 == (0b0110 | 0b0101);
}

int bitwiseExclusiveOr() {
    return 0b0011 == (0b0110 ^ 0b0101);
}

int bitwiseShiftLeft() {
    return 0b0110 == 0b0011 << 1;
}

int bitwiseShiftRight() {
    return 0b0011 == 0b1100 >> 2;
}

int disableFeatureFlag() {
    int feature_flags = 0b00111010;
    int feature_to_disable = 0b00010000;

    feature_flags &= ~(feature_to_disable);

    return 0b00101010 == feature_flags;
}

int checkCtrlQ() {
    int q = 0b01010001;
    int prefixCtrlKey = 0b00011111;
    int ctrlQ = 0b00010001;

    return ctrlQ == (q & prefixCtrlKey);
}

int main(void) {
    VERIFY("bitwise-NOT", bitwiseNot());
    VERIFY("bitwise-AND", bitwiseAnd());
    VERIFY("bitwise-OR", bitwiseOr());
    VERIFY("bitwise-XOR", bitwiseExclusiveOr());
    VERIFY("bitwise-SHIFT-LEFT", bitwiseShiftLeft());
    VERIFY("bitwise-SHIFT-RIGHT", bitwiseShiftRight());
    VERIFY("disable feature flag", disableFeatureFlag());
    VERIFY("check ctrl + Q", checkCtrlQ());
}
