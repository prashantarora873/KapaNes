#include "../include/test_cpu.hpp"

void CPUTest::testOraImm() {
    mem->setByteAt(0x00, 0b00001001);
    mem->setByteAt(0x01, 0b11110000);
    mem->setByteAt(0x02, 0b00001001);
    mem->setByteAt(0x03, 0b10000001);
    cpu->setInstPtr(0x00);
    cpu->executeInstruction(*mem);
    CPPUNIT_ASSERT(cpu->getAccumulator() == 0b11110000);
    cpu->executeInstruction(*mem);
    CPPUNIT_ASSERT(cpu->getAccumulator() == 0b11110001);

}

void CPUTest::testOraIndX() {
    cpu->setInstPtr(0x00);
    cpu->setRegX(0x04);
    mem->setByteAt(0x00, 0b00000001);
    mem->setByteAt(0x01, 0x20);
    mem->setByteAt(0x24, 01);
    mem->setByteAt(0x25, 02);
    mem->setByteAt(0x0201, 0b11100101);
    cpu->executeInstruction(*mem);
    CPPUNIT_ASSERT(cpu->getAccumulator() == 0b11100101);
    
    cpu->setRegX(0x10);
    mem->setByteAt(0x02, 0b00000001);
    mem->setByteAt(0x03, 0xFF);
    mem->setByteAt(0x0F, 0x11);
    mem->setByteAt(0x10, 0x00);
    mem->setByteAt(0x0011, 0b11111111);
    cpu->executeInstruction(*mem);
    CPPUNIT_ASSERT(cpu->getAccumulator() == 0b11111111);

}

void CPUTest::testOraZeroPg() {
    cpu->setInstPtr(0x00);
    mem->setByteAt(0x00, 0b00000101);
    mem->setByteAt(0x01, 0x83);
    mem->setByteAt(0x83, 0b11110110);
    cpu->executeInstruction(*mem);
    CPPUNIT_ASSERT(cpu->getAccumulator() == 0b11110110);

    mem->setByteAt(0x02, 0b00000101);
    mem->setByteAt(0x03, 0x8E);
    mem->setByteAt(0x08E, 0b11111110);
    cpu->executeInstruction(*mem);
    CPPUNIT_ASSERT(cpu->getAccumulator() == 0b11111110);
}

void CPUTest::testOraAbsolute() {
    cpu->setInstPtr(0x00);
    mem->setByteAt(0x00, 0b00001101);
    mem->setByteAt(0x01, 0x10);
    mem->setByteAt(0x02, 0x02);
    mem->setByteAt(0x0210, 0b01010101);
    cpu->executeInstruction(*mem);
    CPPUNIT_ASSERT(cpu->getAccumulator() == 0b01010101);

    mem->setByteAt(0x03, 0b00001101);
    mem->setByteAt(0x04, 0x11);
    mem->setByteAt(0x05, 0x00);
    mem->setByteAt(0x0011, 0b10101010);
    cpu->executeInstruction(*mem);
    CPPUNIT_ASSERT(cpu->getAccumulator() == 0b11111111);
}

void CPUTest::testOraIndirectY() {
    cpu->setInstPtr(0x00);
    mem->setByteAt(0x00, 0b00010001);
    mem->setByteAt(0x01, 0x24);
    cpu->setRegY(0x06);
    mem->setByteAt(0x24, 0x12);
    mem->setByteAt(0x25, 0x01);
    mem->setByteAt(0x0118, 0b1100011);
    cpu->executeInstruction(*mem);
    CPPUNIT_ASSERT(cpu->getAccumulator() == 0b1100011);
}

void CPUTest::testOraZeroPgX() {
    cpu->setInstPtr(0x00);
    cpu->setRegX(0x08);
    mem->setByteAt(0x00, 0b00010101);
    mem->setByteAt(0x01, 0x82);
    mem->setByteAt(0x8A, 0b11100000);
    cpu->executeInstruction(*mem);
    CPPUNIT_ASSERT(cpu->getAccumulator() == 0b11100000);

    mem->setByteAt(0x02, 0b00010101);
    mem->setByteAt(0x03, 0xFF);
    cpu->setRegX(0x11);
    mem->setByteAt(0x10, 0b11111111);
    cpu->executeInstruction(*mem);
    CPPUNIT_ASSERT(cpu->getAccumulator() == 0b11111111);
}

void CPUTest::testOraAbsY() {
    cpu->setInstPtr(0x00);
    cpu->setRegY(0x03);
    mem->setByteAt(0x00, 0b00011001);
    mem->setByteAt(0x01, 0x11);
    mem->setByteAt(0x02, 0x03);
    mem->setByteAt(0x0314, 0b11110000);
    cpu->executeInstruction(*mem);
    CPPUNIT_ASSERT(cpu->getAccumulator() == 0b11110000);
}

void CPUTest::testOraAbsX() {
    cpu->setInstPtr(0x00);
    cpu->setRegX(0x03);
    mem->setByteAt(0x00, 0b00011101);
    mem->setByteAt(0x01, 0x11);
    mem->setByteAt(0x02, 0x03);
    mem->setByteAt(0x0314, 0b11110000);
    cpu->executeInstruction(*mem);
    CPPUNIT_ASSERT(cpu->getAccumulator() == 0b11110000);
}