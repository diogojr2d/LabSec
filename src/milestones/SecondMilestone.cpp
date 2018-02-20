#include "milestones/SecondMilestone.h"

SecondMilestone::~SecondMilestone() {}

void SecondMilestone::generateKeyPairs()
{
    /**
     * Milestone2
     */
    int userLenght = 1024;
    int rootCaLenght = 2048;
    RSAKeyPair userKeyPair (userLenght);
    RSAKeyPair rootCaKeyPair (rootCaLenght);

    ByteArray userKeyPairDER = userKeyPair.getDerEncoded();
    ByteArray rootCaKeyPairDER = rootCaKeyPair.getDerEncoded();

    FileIo::writeToFile(paths::userKeyPairPath, userKeyPairDER);
    FileIo::writeToFile(paths::rootCaKeyPairPath, rootCaKeyPairDER);
}
