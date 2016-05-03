#ifndef KEYCONVERTER_CPP
#define KEYCONVERTER_CPP

#include "keyconverter.hpp"

#include <iostream>
sf::Keyboard::Key QtKeyToSFML(int QtKey)
{
    switch (QtKey)
    {
        /* NUMBERS */
    case Qt::Key_0: return sf::Keyboard::Num0;
    case Qt::Key_1: return sf::Keyboard::Num1;
    case Qt::Key_2: return sf::Keyboard::Num2;
    case Qt::Key_3: return sf::Keyboard::Num3;
    case Qt::Key_4: return sf::Keyboard::Num4;
    case Qt::Key_5: return sf::Keyboard::Num5;
    case Qt::Key_6: return sf::Keyboard::Num6;
    case Qt::Key_7: return sf::Keyboard::Num7;
    case Qt::Key_8: return sf::Keyboard::Num8;
    case Qt::Key_9: return sf::Keyboard::Num9;

    /* ALPHABET */
    case Qt::Key_A: return sf::Keyboard::A;
    case Qt::Key_B: return sf::Keyboard::B;
    case Qt::Key_C: return sf::Keyboard::C;
    case Qt::Key_D: return sf::Keyboard::D;
    case Qt::Key_E: return sf::Keyboard::E;
    case Qt::Key_F: return sf::Keyboard::F;
    case Qt::Key_G: return sf::Keyboard::G;
    case Qt::Key_H: return sf::Keyboard::H;
    case Qt::Key_I: return sf::Keyboard::I;
    case Qt::Key_J: return sf::Keyboard::J;
    case Qt::Key_K: return sf::Keyboard::K;
    case Qt::Key_L: return sf::Keyboard::L;
    case Qt::Key_M: return sf::Keyboard::M;
    case Qt::Key_N: return sf::Keyboard::N;
    case Qt::Key_O: return sf::Keyboard::O;
    case Qt::Key_P: return sf::Keyboard::P;
    case Qt::Key_Q: return sf::Keyboard::Q;
    case Qt::Key_R: return sf::Keyboard::R;
    case Qt::Key_S: return sf::Keyboard::S;
    case Qt::Key_T: return sf::Keyboard::T;
    case Qt::Key_U: return sf::Keyboard::U;
    case Qt::Key_V: return sf::Keyboard::V;
    case Qt::Key_W: return sf::Keyboard::W;
    case Qt::Key_X: return sf::Keyboard::X;
    case Qt::Key_Y: return sf::Keyboard::Y;
    case Qt::Key_Z: return sf::Keyboard::Z;

        /* F's */
    case Qt::Key_F1:    return sf::Keyboard::F1;
    case Qt::Key_F2:    return sf::Keyboard::F2;
    case Qt::Key_F3:    return sf::Keyboard::F3;
    case Qt::Key_F4:    return sf::Keyboard::F4;
    case Qt::Key_F5:    return sf::Keyboard::F5;
    case Qt::Key_F6:    return sf::Keyboard::F6;
    case Qt::Key_F7:    return sf::Keyboard::F7;
    case Qt::Key_F8:    return sf::Keyboard::F8;
    case Qt::Key_F9:    return sf::Keyboard::F9;
    case Qt::Key_F10:   return sf::Keyboard::F10;
    case Qt::Key_F11:   return sf::Keyboard::F11;
    case Qt::Key_F12:   return sf::Keyboard::F12;

        /* ARROWS */
    case Qt::Key_Up:    return sf::Keyboard::Up;
    case Qt::Key_Down:  return sf::Keyboard::Down;
    case Qt::Key_Left:  return sf::Keyboard::Left;
    case Qt::Key_Right: return sf::Keyboard::Right;

        /* MATHS */
    case Qt::Key_Plus:     return sf::Keyboard::Add;
    case Qt::Key_Minus:    return sf::Keyboard::Subtract;
    case Qt::Key_Asterisk: return sf::Keyboard::Multiply;

        /* OTHERS */
    case Qt::Key_End:          return sf::Keyboard::End;
    case Qt::Key_Tab:          return sf::Keyboard::Tab;
    case Qt::Key_Home:         return sf::Keyboard::Home;
    case Qt::Key_Alt:          return sf::Keyboard::RAlt;
    case Qt::Key_Menu:         return sf::Keyboard::Menu;
    case Qt::Key_QuoteDbl:     /*v v v v v v v v v v v v*/
    case Qt::Key_QuoteLeft:    return sf::Keyboard::Quote;
    case Qt::Key_Atilde:       /*v v v v v v v v v v v v*/
    case Qt::Key_Ntilde:       /*v v v v v v v v v v v v*/
    case Qt::Key_Otilde:       /*v v v v v v v v v v v v*/
    case Qt::Key_AsciiTilde:   return sf::Keyboard::Tilde;
    case Qt::Key_Space:        return sf::Keyboard::Space;
    case Qt::Key_Slash:        return sf::Keyboard::Slash;
    case Qt::Key_Comma:        return sf::Keyboard::Comma;
    case Qt::Key_Equal:        return sf::Keyboard::Equal;
    case Qt::Key_Pause:        return sf::Keyboard::Pause;
    case Qt::Key_Return:       return sf::Keyboard::Return;
    case Qt::Key_Escape:       return sf::Keyboard::Escape;
    case Qt::Key_Shift:        return sf::Keyboard::RShift;
    case Qt::Key_Period:       return sf::Keyboard::Period;
    case Qt::Key_PageUp:       return sf::Keyboard::PageUp;
    case Qt::Key_Insert:       return sf::Keyboard::Insert;
    case Qt::Key_Delete:       return sf::Keyboard::Delete;
    case Qt::Key_Super_L:      return sf::Keyboard::LSystem;
    case Qt::Key_Super_R:      return sf::Keyboard::RSystem;
    case Qt::Key_Control:      return sf::Keyboard::RControl;
    case Qt::Key_BracketLeft:  return sf::Keyboard::LBracket;
    case Qt::Key_BracketRight: return sf::Keyboard::RBracket;
    case Qt::Key_PageDown:     return sf::Keyboard::PageDown;
    case Qt::Key_Backslash:    return sf::Keyboard::BackSlash;
    case Qt::Key_Backspace:    return sf::Keyboard::BackSpace;
    case Qt::Key_Semicolon:    return sf::Keyboard::SemiColon;

    default:
        std::cout << QtKey << std::endl;
        return sf::Keyboard::Unknown;
    }
}

#endif // KEYCONVERTER_CPP

