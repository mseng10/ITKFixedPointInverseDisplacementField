/*=========================================================================
 *
 *  Copyright Insight Software Consortium
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *         http://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/
#ifndef itkFixedPointInverseDisplacementFieldImageFilter_h
#define itkFixedPointInverseDisplacementFieldImageFilter_h


#include "itkImageToImageFilter.h"

#include "itkWarpVectorImageFilter.h"
#include "itkVectorLinearInterpolateImageFunction.h"
#include "itkImageRegionIterator.h"
#include "itkTimeProbe.h"

namespace itk
{

/** \class FixedPointInverseDisplacementFieldImageFilter
 * \brief Computes the inverse of a Displacement field using a fixed point iteration scheme.
 *
 * FixedPointInverseDisplacementFieldImageFilter takes a Displacement field as input and
 * computes the Displacement field that is its inverse. If the input Displacement
 * field was mapping coordinates from a space A into a space B, the output of
 * this filter will map coordinates from the space B into the space A.
 *
 * To compute the inverse of the given Displacement field, the fixed point algorithm by
 * Mingli Chen, Weiguo Lu, Quan Chen, Knneth J. Ruchala and Gusavo H. Olivera
 * described in the paper
 * "A simple fixed-point approach to invert a Displacement field",
 * Medical Physics, vol. 35, issue 1, p. 81,
 * is applied.
 *
 * \author Marcel L�thi, Computer Science Department, University of Basel
 *
 * \ingroup ImageToImageFilter
 * \ingroup FixedPointInverseDisplacementField
 */

template < class TInputImage, class TOutputImage >
class ITK_EXPORT FixedPointInverseDisplacementFieldImageFilter :
    public ImageToImageFilter<TInputImage,TOutputImage>
{
public:
  /** Standard class typedefs. */
  typedef FixedPointInverseDisplacementFieldImageFilter   Self;
  typedef ImageToImageFilter<TInputImage,TOutputImage>    Superclass;
  typedef SmartPointer<Self>                              Pointer;
  typedef SmartPointer<const Self>                        ConstPointer;

  /** Method for creation through the object factory. */
  itkNewMacro(Self);

  /** Run-time type information (and related methods). */
  itkTypeMacro(FixedPointInverseDisplacementFieldImageFilter, ImageToImageFilter);


  /** Some typedefs. */
  typedef TInputImage                              InputImageType;
  typedef typename InputImageType::ConstPointer    InputImageConstPointer;
  typedef typename InputImageType::Pointer         InputImagePointer;
  typedef typename InputImageType::PointType       InputImagePointType;
  typedef typename InputImageType::RegionType      InputImageRegionType;
  typedef typename InputImageType::SpacingType     InputImageSpacingType;
  typedef typename InputImageType::IndexType       InputImageIndexType;


  typedef TOutputImage                             OutputImageType;
  typedef typename OutputImageType::Pointer        OutputImagePointer;
  typedef typename OutputImageType::PixelType      OutputImagePixelType;
  typedef typename OutputImageType::PointType      OutputImagePointType;
  typedef typename OutputImageType::IndexType      OutputImageIndexType;
  typedef typename OutputImagePixelType::ValueType OutputImageValueType;
  typedef typename OutputImageType::SizeType       OutputImageSizeType;
  typedef typename OutputImageType::SpacingType    OutputImageSpacingType;
  typedef typename TOutputImage::PointType         OutputImageOriginPointType;
  typedef TimeProbe                                TimeType;


  /** Number of dimensions. */
  itkStaticConstMacro(ImageDimension, unsigned int,
                      TOutputImage::ImageDimension);

  typedef ImageRegionConstIterator<InputImageType>  InputConstIterator;
  typedef ImageRegionIterator<InputImageType>       InputIterator;
  typedef ImageRegionConstIterator<OutputImageType> OutputConstIterator;
  typedef ImageRegionIterator<OutputImageType>      OutputIterator;

  typedef WarpVectorImageFilter<TOutputImage,TInputImage,TOutputImage>       VectorWarperType;
  typedef typename NumericTraits<typename TOutputImage::PixelType>::RealType InterpolatorVectorType;
  typedef typename TOutputImage::PixelType                                   OutputVectorType;
  typedef VectorLinearInterpolateImageFunction<TInputImage, double>          FieldInterpolatorType;
  typedef typename FieldInterpolatorType::Pointer                            FieldInterpolatorPointer;
  typedef typename FieldInterpolatorType::OutputType                         FieldInterpolatorOutputType;


  itkSetMacro(NumberOfIterations, unsigned int);
  itkGetConstMacro(NumberOfIterations, unsigned int);


  /** Set the size of the output image. */
  itkSetMacro( Size, OutputImageSizeType );
  /** Get the size of the output image. */
  itkGetConstReferenceMacro( Size, OutputImageSizeType );

  /** Set the output image spacing. */
  itkSetMacro(OutputSpacing, OutputImageSpacingType);
  virtual void SetOutputSpacing(const double* values);

  /** Get the output image spacing. */
  itkGetConstReferenceMacro( OutputSpacing, OutputImageSpacingType );

  /** Set the output image origin. */
  itkSetMacro(OutputOrigin, OutputImageOriginPointType);
  virtual void SetOutputOrigin( const double* values);

#ifdef ITK_USE_CONCEPT_CHECKING
  /** Begin concept checking */
  itkConceptMacro(OutputHasNumericTraitsCheck,
                  (Concept::HasNumericTraits<OutputImageValueType>));
  itkConceptMacro( SameDimensionCheck,
                   ( Concept::SameDimension< TInputImage::ImageDimension, TOutputImage::ImageDimension > ) );

  /** End concept checking */
#endif

protected:
  FixedPointInverseDisplacementFieldImageFilter();
  ~FixedPointInverseDisplacementFieldImageFilter() ITK_OVERRIDE {}

  void PrintSelf(std::ostream& os, Indent indent) const ITK_OVERRIDE;

  void GenerateData( ) ITK_OVERRIDE;
  void GenerateOutputInformation() ITK_OVERRIDE;

  void GenerateInputRequestedRegion() ITK_OVERRIDE;

  unsigned int m_NumberOfIterations;


private:
  FixedPointInverseDisplacementFieldImageFilter(const Self&); //purposely not implemented
  void operator=(const Self&); //purposely not implemented

  OutputImageSizeType                      m_Size;              // Size of the output image
  OutputImageSpacingType                   m_OutputSpacing;     // output image spacing
  OutputImageOriginPointType               m_OutputOrigin;      // output image origin


};

} // end namespace itk

#ifndef ITK_MANUAL_INSTANTIATION
#include "itkFixedPointInverseDisplacementFieldImageFilter.hxx"
#endif
#endif
