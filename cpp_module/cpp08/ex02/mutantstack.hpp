/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 11:11:45 by eshakita          #+#    #+#             */
/*   Updated: 2021/10/22 13:44:49 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

/*
std::stack это всего лишь адаптер контейнера. 
Он принимает тип контейнера (std::deque по умолчанию) в качестве параметра шаблона,
и экземпляр stack может быть создан из экземпляра этого контейнера,
но в противном случае базовый частный контейнер не отображается, а сам стек не имеет средств итерации.

для того, что бы получить доступ к базовому защищенному контейнеру deque из контейнера stack обращаемся через .c
напрямую обратиться к .c мы не можем так как .c явлеятся приватным методом. можем это сдалать через наследование.
*/

template <typename T>
class MutantStack : public std::stack<T>
{
private:
public:
    /*
    что бы вернуть какой свой тип(тайп нейм), нужно объявить шаблон тайпнейма
    без такого шаблона компилятор не разрешает это сделать.

    посколько stack->deque то мы имеем право возвращать итератор deque
    но если мы захотим указать именно stack то нужно дабавить в область видимости контейнер тайп
    в первом случае компилятор дает ретернить итератор через this->c.begin()
    во втором через MutantStack<T>::c.begin();

    оба вариант верны.
    
    в deque итераторы:
    begin end rbegin rend
    cbegin cend crbegin crend - константная версия обычных итератор появилась в С++11
    Первое отличие состоит в том, 
    что cbegin не имеет перегрузок и имеет квалификацию const,
    в то время как begin перегружен двумя функциями,
    одна из которых имеет квалификацию const, а другая-нет.
    
    Второе различие заключается в типе итератора, 
    который они возвращают. 
    Согласно документации, cbegin возвращает const_iterator, 
    в то время как одна перегрузка begin возвращает iterator, 
    а другая возвращает const_iterator (например, cbegin ).
    */
   
    typedef typename std::deque<T>::iterator                        iterator;
    // typedef typename std::stack<T>::container_type::iterator    iterator;
    typedef typename std::deque<T>::reverse_iterator                reverse_iterator;
    typedef typename std::deque<T>::const_iterator                  const_iterator;
    typedef typename std::deque<T>::const_reverse_iterator          const_reverse_iterator;
    MutantStack() {};
    MutantStack(const MutantStack<T> &new_stack)
    {
        this->c = new_stack.c;
    };
    MutantStack<T> &operator=(const MutantStack<T> &new_stack)
    {
		this->c = new_stack.c;
        return(*this);
    }
    virtual ~MutantStack(){};
    
    
    // std::iterator begin() { return MutantStack<T>::c.begin(); };
    iterator begin()                { return this->c.begin(); };
    reverse_iterator rbegin()       { return this->c.rbegin(); };
    const_iterator cbegin()         { return this->c.cbegin(); };
    const_reverse_iterator crbegin() { return this->c.crbegin(); };
    
    iterator end()                  { return this->c.end(); };
    reverse_iterator rend()         { return this->c.rend(); };
    const_iterator cend()           { return this->c.cend(); };
    const_reverse_iterator crend()   { return this->c.crend(); };
};

#endif