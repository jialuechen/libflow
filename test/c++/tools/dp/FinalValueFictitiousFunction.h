
#ifndef   FINALVALUEFICTITIOUSFUNCTION_H
#define   FINALVALUEFICTITIOUSFUNCTION_H
#include <iostream>
#include <Eigen/Dense>


template< class PayOff >
class FinalValueFictitiousFunction
{
private :

    PayOff m_pay ;
    int m_nExerc;

public :
    /// \brief Constructor
    FinalValueFictitiousFunction(const PayOff &p_pay, const int &p_nExerc): m_pay(p_pay), m_nExerc(p_nExerc) {}


/// \brief final function
/// \param  p_stock  position in the stock
/// \param  p_state  position in the stochastic state
    inline double operator()(const int &, const Eigen::ArrayXd &p_stock, const Eigen::ArrayXd   &p_state) const
    {
        int idec = p_stock.size() * m_nExerc - p_stock.sum();
        return  std::min(idec, static_cast<int>(p_stock.size())) * m_pay.apply(p_state.matrix());
    }
};
#endif /* FINALVALUEFICTITIOUSFUNCTION_H */
