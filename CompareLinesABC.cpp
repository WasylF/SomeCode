
    template <typename tPoint, typename tParam>
    bool operator==(LineABC<tPoint,tParam>  & l1, LineABC<tPoint,tParam>  & l2)
    {
        tParam a1,b1,c1,a2,b2,c2;
        l1.getABC(a1,b1,c1);
        l2.getABC(a2,b2,c2);


        if (fabs(a1)>eps && fabs(a2)>eps)
        {
            b1/= a1; c1/= a1;
            b2/= a2; c2/= a2;
            return ((fabs(b1-b2)<eps)&&(fabs(c1-c2)<eps));
        }

        if (fabs(b1)>eps && fabs(b2)>eps)
        {
            a1/= b1; c1/= b1;
            a2/= b2; c2/= b2;
            return ((fabs(a1-a2)<eps)&&(fabs(c1-c2)<eps));
        }

        if (fabs(c1)>eps && fabs(c2)>eps)
        {
            a1/= c1; b1/= c1;
            a2/= c2; b2/= c2;
            return ((fabs(a1-a2)<eps)&&(fabs(b1-b2)<eps));
        }

        return false;
    }
