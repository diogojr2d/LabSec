#include "utils/FileIo.h"

FileIo::~FileIo() {}

ByteArray FileIo::readFile(const char* filePath)
{
    /**
     * Milestone1
     */

    ByteArray ret;
    fstream file (filePath, ios::in|ios::binary|ios::ate);

    if (file.is_open()) {
        streampos size = file.tellg();
        char* memblock = new char[size];
        file.seekg(0, ios::beg);
        file.read(memblock, size);
        file.close();

        ret = ByteArray(memblock);
    } else {
        throw IoException(filePath, IoException::READ_FAILED);
    }

	return ret;
}

void FileIo::writeToFile(const char* filePath, ByteArray& data)
{
    /**
     * Milestone2
     */
    fstream file (filePath, ios::out|ios::binary|ios::trunc);
    if (file.is_open()) {
        file.write((const char *)data.getDataPointer(), data.size());
        file.close();
    } else {
        throw IoException(filePath, IoException::WRITE_FAILED);
    }

}
