#include "milestones/FirstMilestone.h"

FirstMilestone::~FirstMilestone() {}

ByteArray FirstMilestone::computeHash()
{
    /**
     * Milestone1
     */
    ByteArray data = FileIo::readFile(paths::plainText);
    MessageDigest myMessage(MessageDigest::SHA1);
    myMessage.update(data);

    ByteArray hash = myMessage.doFinal();
    return hash;
}
