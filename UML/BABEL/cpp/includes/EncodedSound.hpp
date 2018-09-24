#ifndef BABEL_ENCODEDSOUND_H
#define BABEL_ENCODEDSOUND_H


namespace Babel {

//This struct contain a "Encoded sound"
struct EncodedSound {
    std::vector<unsigned char> _buffer;

    unsigned long _size = 0;

};

} // namespace Babel
#endif
