
class DEVSIntegrator(object):
    def __init__(self, xmile_stock):
        self.stock = xmile_stock
        self.name = xmile_stock.getName()
        self.access = xmile_stock.getAccess()
        self.equation = xmile_stock.getEquation()
        self.integrator_type = 'QSS1'
        self.integrator_parameters = {
            'x0'    : self.equation, # TODO : verificar que esto sea un numero (requiere previa normalizacion)
            'dQRel' : '0.001',
            'dQMin' : '0.001'
        }
    def __repr__(self):
        return str({
            'name' : self.name,
            'access' : self.access,
            'equation' : self.equation,
            'integrator_type' : self.integrator_type,
            'integrator_parameters' : self.integrator_parameters
        })
    def __str__(self):
        return str({
            'name' : self.name,
            'access' : self.access,
            'equation' : self.equation,
            'integrator_type' : self.integrator_type,
            'integrator_parameters' : self.integrator_parameters
        })