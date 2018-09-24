#ifndef BABEL_DECODEDSOUND_H
#define BABEL_DECODEDSOUND_H


namespace Babel {

//This structure contain a "Decoded sound"
struct DecodedSound {
    std::vector<float> _buffer;

    unsigned long _size = 0;

};

} // namespace Babel
#endif
