#pragma once

#include "JSystem/JGeometry/TVec.hpp"
#include "JSystem/JGeometry/TQuat.hpp"
#include <cmath>

namespace JGeometry {
    template<typename T>
    struct SMatrix34C {
    public:

        typedef f32 ArrType[4];
        void set(const ArrType*);
        void set(const SMatrix34C<T> &rSrc);
        void set(T rxx, T ryx, T rzx, T tx, T rxy, T ryy, T rzy, T ty, T rxz, T ryz, T rzz, T tz);

        void scale(T);

        inline void setInline(const SMatrix34C<T> &rSrc) {
            #ifdef __MWERKS__
            register const SMatrix34C<T> *pSrc = &rSrc;
            register SMatrix34C<T> *pDest = this;
            register f32 rzztz;
            register f32 rxzyz;
            register f32 rzyty;
            register f32 rxyyy;
            register f32 rzxtx;
            register f32 rxxyx;

            __asm {
                psq_l     rxxyx, 0(pSrc), 0, 0
                psq_l     rzxtx, 8(pSrc), 0, 0
                psq_l     rxyyy, 0x10(pSrc), 0, 0
                psq_l     rzyty, 0x18(pSrc), 0, 0
                psq_l     rxzyz, 0x20(pSrc), 0, 0
                psq_l     rzztz, 0x28(pSrc), 0, 0
                psq_st    rxxyx, 0(pDest), 0, 0
                psq_st    rzxtx, 8(pDest), 0, 0
                psq_st    rxyyy, 0x10(pDest), 0, 0
                psq_st    rzyty, 0x18(pDest), 0, 0
                psq_st    rxzyz, 0x20(pDest), 0, 0
                psq_st    rzztz, 0x28(pDest), 0, 0
            };
            #endif
        }

        inline void setInline(const MtxPtr rSrc) {
            #ifdef __MWERKS__
            register const MtxPtr pSrc = rSrc;
            register SMatrix34C<T> *pDest = this;
            register f32 rzztz;
            register f32 rxzyz;
            register f32 rzyty;
            register f32 rxyyy;
            register f32 rzxtx;
            register f32 rxxyx;

            __asm {
                psq_l     rxxyx, 0(pSrc), 0, 0
                psq_l     rzxtx, 8(pSrc), 0, 0
                psq_l     rxyyy, 0x10(pSrc), 0, 0
                psq_l     rzyty, 0x18(pSrc), 0, 0
                psq_l     rxzyz, 0x20(pSrc), 0, 0
                psq_l     rzztz, 0x28(pSrc), 0, 0
                psq_st    rxxyx, 0(pDest), 0, 0
                psq_st    rzxtx, 8(pDest), 0, 0
                psq_st    rxyyy, 0x10(pDest), 0, 0
                psq_st    rzyty, 0x18(pDest), 0, 0
                psq_st    rxzyz, 0x20(pDest), 0, 0
                psq_st    rzztz, 0x28(pDest), 0, 0
            };
            #endif
        }

        inline void setInline_2(MtxPtr rSrc) {
            #ifdef __MWERKS__
            register MtxPtr pSrc = rSrc;
            register SMatrix34C<T> *pDest = this;
            register f32 rzztz;
            register f32 rxzyz;
            register f32 rzyty;
            register f32 rxyyy;
            register f32 rzxtx;
            register f32 rxxyx;

            __asm {
                psq_l     rxxyx, 0(pSrc), 0, 0
                psq_l     rzxtx, 8(pSrc), 0, 0
                psq_l     rxyyy, 0x10(pSrc), 0, 0
                psq_st    rxxyx, 0(pDest), 0, 0
                psq_l     rzyty, 0x18(pSrc), 0, 0
                psq_st    rzxtx, 8(pDest), 0, 0
                psq_l     rxzyz, 0x20(pSrc), 0, 0
                psq_st    rxyyy, 0x10(pDest), 0, 0
                psq_l     rzztz, 0x28(pSrc), 0, 0
                psq_st    rzyty, 0x18(pDest), 0, 0
                psq_st    rxzyz, 0x20(pDest), 0, 0
                psq_st    rzztz, 0x28(pDest), 0, 0
            };
            #endif
        }

        inline Mtx* toMtx() {
            return (Mtx*)mMtx;
        }

        inline const Mtx* toCMtx() const {
            return (const Mtx*)mMtx;
        }

        inline MtxPtr toMtxPtr() {
            return (MtxPtr)mMtx;
        }

        operator ArrType*() {
            return mMtx;
        }

        operator const ArrType*() const {
            return mMtx;
        }
        
        f32 get(int x, int y) const { 
            return mMtx[x][y];
        }

        f32 operator()(int x, int y) const {
            return get(x, y);
        }

        
        __attribute__((always_inline))
        inline f32 dot() const {
            return(
                (this->mMtx[1][0] * this->mMtx[1][0]) +
                (this->mMtx[0][0] * this->mMtx[0][0]) +
                (this->mMtx[2][0] * this->mMtx[2][0]) +
                (this->mMtx[0][1] * this->mMtx[0][1]) +
                (this->mMtx[1][1] * this->mMtx[1][1]) +
                (this->mMtx[2][1] * this->mMtx[2][1]) +
                (this->mMtx[0][2] * this->mMtx[0][2]) +
                (this->mMtx[1][2] * this->mMtx[1][2]) +
                (this->mMtx[2][2] * this->mMtx[2][2])
            );
        }

        inline f32 dot(int x, int y) {
            return (this->mMtx[x][y] * this->mMtx[x][y]);
        }

        inline f32 dotX() const {
            //f32 _10 = ;
            //f32 _20 = ;
            //f32 _00 = ;
            
            return (this->mMtx[1][0] * this->mMtx[1][0]) + (this->mMtx[0][0] * this->mMtx[0][0]) + (this->mMtx[2][0] * this->mMtx[2][0]);
        }

        inline f32 dotY() const {
            //f32 _11 = ;
            //f32 _21 = ;
            //f32 _01 = ;
            
            return (this->mMtx[1][1] * this->mMtx[1][1]) + (this->mMtx[0][1] * this->mMtx[0][1]) + (this->mMtx[2][1] * this->mMtx[2][1]);
        }

        inline f32 dotZ() const {
            //f32 _12 = ;
            //f32 _22 = ;
            //f32 _02 = ;
            
            return (this->mMtx[1][2] * this->mMtx[1][2]) + (this->mMtx[0][2] * this->mMtx[0][2]) + (this->mMtx[2][2] * this->mMtx[2][2]);
        }

        inline f32 dot(int x, int y) const {
            return (this->mMtx[x][y] * this->mMtx[x][y]);
        }

        T mMtx[3][4];
    };

    template<typename T>
    struct TMatrix34 : public T {
    public:
        void identity();
        void concat(const T &rSrcA, const T &rSrcB);
        void concat(const T &rSrc);
        void invert(const TMatrix34<T> &rDest);

        void mult(const TVec3f &rSrc, TVec3f &rDest) const;

        void multTranspose(const TVec3f &a1, const TVec3f &a2) const;
    };
    template<class T>
    struct TRotation3 : public T {
    public:
        void identity33();

        void getXDir(TVec3f &rDest) const NO_INLINE {
            rDest.set(this->mMtx[0][0], this->mMtx[1][0], this->mMtx[2][0]);
        };

        void getYDir(TVec3f &rDest) const NO_INLINE {
            rDest.set(this->mMtx[0][1], this->mMtx[1][1], this->mMtx[2][1]);
        };

        void getZDir(TVec3f &rDest) const NO_INLINE {
            rDest.set(this->mMtx[0][2], this->mMtx[1][2], this->mMtx[2][2]);
        };

        void getXYZDir(TVec3f &rDestX, TVec3f &rDestY, TVec3f &rDestZ) const;
        void setXDir(const TVec3f &rSrc);
        void setXDir(f32 x, f32 y, f32 z);
        void setYDir(const TVec3f &rSrc);
        void setYDir(f32 x, f32 y, f32 z);
        void setZDir(const TVec3f &rSrc);
        void setZDir(f32 x, f32 y, f32 z);
        void setXYZDir(const TVec3f &rSrcX, const TVec3f &rSrcY, const TVec3f &rSrcZ);

        void getEuler(TVec3f &rDest) const;
        void getEulerXYZ(TVec3f &rDest) const;
        void setEulerY(f32 val);
        void setEulerZ(f32 val);

        void getQuat(TQuat4f &rDest) const;
        void setQuat(const TQuat4f &rSrc);

        void getScale(TVec3f &rDest) const;
        void setScale(const TVec3f &rSrc);
        void setRotate(const TVec3f &, f32);
        void mult33(TVec3f &) const;
        void mult33(const TVec3f &rDst, TVec3f &rSrc) const;

        inline void getXDirInline(TVec3f &rDest) const {
            f32 z = this->mMtx[2][0];
            f32 y = this->mMtx[1][0];
            f32 x = this->mMtx[0][0];
            rDest.set<f32>(x, y, z);
        }

        inline void zeroTrans() {
            this->mMtx[0][3] = 0.0f;
            this->mMtx[1][3] = 0.0f;
            this->mMtx[2][3] = 0.0f;
        }

        inline void makeRotateInline(const TVec3f &rVec, f32 r) {
            zeroTrans();
            setRotateInline(rVec, r);
        }

        inline void setRotateInline2(f32 y, f32 p) {
            f32 v9 = (0.017453292 * y);
            f32 v10 = -(0.017453292f * p);

            f32 v11 = cos(0.0f);
            f32 v12 = cos(v9);
            f32 v13 = cos(v10);
            f32 v14 = sin(0.0f);
            f32 v15 = sin(v9);
            f32 v16 = sin(v10);

            this->mMtx[0][0] = v12 * v13;
            this->mMtx[0][1] = (v16 * v11) - (v15 * v14);
            this->mMtx[0][2] = (v15 * v11) + (v16 * v14);
            this->mMtx[1][0] = v15;
            this->mMtx[1][1] = v12 * v11;
            this->mMtx[1][2] = -v12 * v14;
            this->mMtx[2][0] = -v14;
            this->mMtx[2][1] = v13 * v14;
            this->mMtx[2][2] = v13 * v11;
        }

        inline void setRotateInline(f32 r, f32 n) {
            f32 c, s, angle;
            angle = n * r;
            s = sin(angle);
            c = cos(angle);

            this->mMtx[0][2] = s;
            this->mMtx[1][1] = 1.0f;
            this->mMtx[0][0] = c;
            this->mMtx[2][0] = -s;
            this->mMtx[2][2] = c;
            this->mMtx[2][1] = 0.0f;
            this->mMtx[1][2] = 0.0f;
            this->mMtx[1][0] = 0.0f;
            this->mMtx[0][1] = 0.0f; 
        }

        inline void someInlineMatrixFunction(f32 y, f32 p) {
            f32 HUNDERDEIGHTIETHPI = 0.017453292f;
            f32 v9 = (HUNDERDEIGHTIETHPI * y); // f25
            f32 v10 = -(HUNDERDEIGHTIETHPI * p); //f24

            f32 v11 = cos(0.0f); //f28
            f32 v12 = cos(v9); // f27
            f32 v13 = cos(v10); // f26
            f32 v14 = sin(0.0f); //f23
            f32 v15 = sin(v9); // f25
            f32 v16 = sin(v10); //f9

            this->mMtx[0][0] = v12 * v11;
            this->mMtx[0][1] = ( v16 * v15 * v11) - (v13 * v14);
            this->mMtx[1][0] = v12 * v14;
            this->mMtx[1][1] = (v13 * v11) + (v16 * v15 * v14) ;
            this->mMtx[2][0] = -v15;
            this->mMtx[2][1] = v16 * v12;
            this->mMtx[0][2] = (v13 * v11 * v15) + (v16 * v14);
            this->mMtx[1][2] = (v13 * v14 * v15) - (v16 * v11);
            this->mMtx[2][2] = v12 * v13;
        }

        inline void setRotateInline(const TVec3f &vec1, f32 r) {
            TVec3f vec;
            vec.set(vec1);
            PSVECMag(&vec);
            PSVECNormalize(&vec, &vec);
            f32 s = sin(r);
            f32 c = cos(r);
            f32 negc = (1.0f - c);
            f32 x = vec.x;
            f32 y = vec.y;
            f32 z = vec.z;

            this->mMtx[0][0] = (negc * (x * x) + c); 
            this->mMtx[0][1] = (y * (negc * x)) - (s * z);  
            this->mMtx[0][2] = (z * (negc * x)) + (s * y);
            this->mMtx[1][0] = (y * (negc * x)) + (s * z);
            this->mMtx[1][1] = (negc * (y * y) + c);
            this->mMtx[1][2] = (z * (negc * y)) - (s * x);
            this->mMtx[2][0] = (z * (negc * x)) - (s * y);
            this->mMtx[2][1] = (z * (negc * y)) + (s * x);
            this->mMtx[2][2] = (negc * (z * z) + c);
        }
        void setRotateInline2(const TVec3f &vec1, f32 r) {
            // The only difference from setRotateInline is that we use setInline instead of set
            TVec3f vec;
            vec.x = vec1.x;
            vec.y = vec1.y;
            vec.z = vec1.z;
            PSVECMag(&vec);
            PSVECNormalize(&vec, &vec);
            f32 s = sin(r);
            f32 c = cos(r);
            f32 negc = (1.0f - c);
            f32 x = vec.x;
            f32 y = vec.y;
            f32 z = vec.z;

            this->mMtx[0][0] = (negc * (x * x) + c); 
            this->mMtx[0][1] = (y * (negc * x)) - (s * z);  
            this->mMtx[0][2] = (z * (negc * x)) + (s * y);
            this->mMtx[1][0] = (y * (negc * x)) + (s * z);
            this->mMtx[1][1] = (negc * (y * y) + c);
            this->mMtx[1][2] = (z * (negc * y)) - (s * x);
            this->mMtx[2][0] = (z * (negc * x)) - (s * y);
            this->mMtx[2][1] = (z * (negc * y)) + (s * x);
            this->mMtx[2][2] = (negc * (z * z) + c);
        }



        inline void mult33Inline(const TVec3f &rSrc, TVec3f &rDst) const {
            f32 a32, a22, a12, a11, a21, vx, a31, vy, a23, a33, a13;
            a32 = this->mMtx[2][1];
            a22 = this->mMtx[1][1];
            a12 = this->mMtx[0][1];
            a31 = this->mMtx[2][0];
            a21 = this->mMtx[1][0];
            a11 = this->mMtx[0][0];
            a33 = this->mMtx[2][2];
            a13 = this->mMtx[0][2];
            a23 = this->mMtx[1][2];
            f32 x, y;
            vx = rSrc.x;
            vy = rSrc.y;
            x = (vx * a11 + vy * a12);
            rDst.set<f32>(rSrc.z * a13 + (vx * a11 + vy * a12), rSrc.z * a23 + (vx * a21 + vy * a22), rSrc.z * a33 + (rSrc.x * a31 + rSrc.y * a32));
        }
    };

    template<class T>
    struct TPosition3 : public TRotation3<T> {
    public:
        void getTrans(TVec3f &rDest) const;
        void setTrans(const TVec3f &rSrc);
        void setTrans(f32 x, f32 y, f32 z);
        void zeroTrans();

        void makeRotate(const TVec3f &, f32);
        void makeQuat(const TQuat4f &rSrc);
        void setPositionFromLookAt(const TPosition3<T> &rLookAt);
        void setQT(const TQuat4f &rSrcQuat, const TVec3f &rSrcTrans);

        f32 get(int x, int y) const { 
            return this->mMtx[x][y];
        }

        f32 operator()(int x, int y) const {
            return get(x, y);
        }

        inline void getTransInline(TVec3f &rDest) const {
            f32 z = this->mMtx[2][3];
            f32 y = this->mMtx[1][3];
            f32 x = this->mMtx[0][3];
            rDest.set<f32>(x, y, z);
        }

        inline void setVec(const TVec3f &a1, const TVec3f &a2, const TVec3f &a3) {
            this->mMtx[0][0] = a1.x;
            this->mMtx[1][0] = a1.y;
            this->mMtx[2][0] = a1.z;

            this->mMtx[0][1] = a2.x;
            this->mMtx[1][1] = a2.y;
            this->mMtx[2][1] = a2.z;

            this->mMtx[0][2] = a3.x;
            this->mMtx[1][2] = a3.y;
            this->mMtx[2][2] = a3.z;
        }
    };
};

typedef JGeometry::SMatrix34C<f32> TSMtxf;
typedef JGeometry::TMatrix34<TSMtxf> TMtx34f;
typedef JGeometry::TRotation3<TMtx34f> TRot3f;
typedef JGeometry::TPosition3<TMtx34f> TPos3f;
